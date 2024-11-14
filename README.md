import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.*;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.HashMap;

// Main Application Class
public class App extends Application {
    private Scene loginScene, registerScene, homeScene, createEventScene;
    private VBox eventListBox;
    private UserManager userManager = new UserManager();
    private User currentUser = null; // Track currently logged-in user
    private TextField eventNameField, dateField;
    private ArrayList<String> toDoList = new ArrayList<>();
    private AttendeeManager attendeeManager;
    private FoodManager food;
    private VenueDecoration venueDecoration;
    private VBox toDoCheckboxes;
    private DatePicker datePicker;

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Event Management System");

        initLoginScene(primaryStage);
        initRegisterScene(primaryStage);
        initHomeScene(primaryStage);
        initCreateEventScene(primaryStage);

        primaryStage.setScene(loginScene);
        primaryStage.show();
    }

    // Login Scene
    private void initLoginScene(Stage primaryStage) {
        VBox layout = new VBox(10);
        TextField usernameField = new TextField();
        PasswordField passwordField = new PasswordField();
        Button loginButton = new Button("Login");
        Button registerButton = new Button("Register");

        loginButton.setOnAction(e -> {
            String username = usernameField.getText();
            String password = passwordField.getText();
            User user = userManager.login(username, password);
            if (user != null) {
                currentUser = user; // Set the current user
                updateHomeScene();
                primaryStage.setScene(homeScene);
            } else {
                showAlert("Login Failed", "Invalid username or password");
            }
        });

        registerButton.setOnAction(e -> primaryStage.setScene(registerScene));

        layout.getChildren().addAll(new Label("Username:"), usernameField, new Label("Password:"), passwordField, loginButton, registerButton);
        loginScene = new Scene(layout, 300, 200);
    }

    // Register Scene
    private void initRegisterScene(Stage primaryStage) {
        VBox layout = new VBox(10);
        TextField usernameField = new TextField();
        PasswordField passwordField = new PasswordField();
        Button registerButton = new Button("Register");
        Button backButton = new Button("Back");

        registerButton.setOnAction(e -> {
            String username = usernameField.getText();
            String password = passwordField.getText();
            if (userManager.register(username, password)) {
                primaryStage.setScene(loginScene);
            } else {
                showAlert("Registration Failed", "User already exists");
            }
        });

        backButton.setOnAction(e -> primaryStage.setScene(loginScene));

        layout.getChildren().addAll(new Label("Username:"), usernameField, new Label("Password:"), passwordField, registerButton, backButton);
        registerScene = new Scene(layout, 300, 200);
    }

    // Home Scene
    private void initHomeScene(Stage primaryStage) {
        VBox layout = new VBox(10);
        Label titleLabel = new Label("Event Dashboard");
        eventListBox = new VBox(10);
        Button createEventButton = new Button("Create Event");
        Button logoutButton = new Button("Logout");

        createEventButton.setOnAction(e ->{
            
             primaryStage.setScene(createEventScene);
             resetCreateEventScene();
        });
        logoutButton.setOnAction(e -> {
            currentUser = null; // Clear the current user on logout
            primaryStage.setScene(loginScene);
        });

        layout.getChildren().addAll(titleLabel, eventListBox, createEventButton, logoutButton);
        homeScene = new Scene(layout, 700, 400);
    }

    // Update Home Scene with current user's events
    private void updateHomeScene() {
        eventListBox.getChildren().clear();
        if (currentUser.getEvents().isEmpty()) {
            eventListBox.getChildren().add(new Label("No events added."));
        } else {
            for (Event event : currentUser.getEvents()) {
                Button eventButton = new Button(event.getName());
                eventButton.setOnAction(e -> showEventDetails(event));
                eventListBox.getChildren().add(eventButton);
            }
        }
    }

    // Create Event Scene
    private void initCreateEventScene(Stage primaryStage) {
        VBox layout = new VBox(10);
        eventNameField = new TextField();
        eventNameField.setPromptText("Event Name");

        dateField = new TextField("select date");
        VBox calendarLayout = new VBox(10);
        datePicker = new DatePicker();

        dateField.setPromptText("Choose Date");

        datePicker.setOnAction(e -> {
            String date = datePicker.getValue().toString();
            dateField.setText(date);
        });
        calendarLayout.getChildren().addAll(datePicker);

        Button addGuestButton = new Button("Add Guests");
        Button setVenueButton = new Button("Set Venue");
        Button addFoodButton = new Button("Add Food Items");
        Button setThemeButton = new Button("Set Decoration Theme");
        Button addToDoButton = new Button("Add To-Do List");
        Button saveEventButton = new Button("Save Event");
        Button backButton = new Button("Back");

        attendeeManager = new AttendeeManager();
        food = new FoodManager();
        venueDecoration = new VenueDecoration();
        toDoList = new ArrayList<>();
        // Guest Management
        addGuestButton.setOnAction(e -> {
            VBox guestLayout = new VBox(10);
            Label guestCountLabel = new Label("Guests: "+attendeeManager.getGuestCount());
            guestLayout.getChildren().add(guestCountLabel); 
            ListView<String> guestListView = new ListView<>();
            guestListView.getItems().addAll(attendeeManager.guestList);
            
            // Button to add new guest
            Button addNewGuestButton = new Button("Add Guest");
            addNewGuestButton.setOnAction(event -> {
                
                    TextInputDialog dialog = new TextInputDialog();
                    dialog.setTitle("Add Guest");
                    dialog.setHeaderText("Enter guest name:");
                    dialog.showAndWait().ifPresent(guestName -> {
                        if (attendeeManager.addGuest(guestName)) {
                            guestListView.getItems().clear();
                            guestListView.getItems().addAll(attendeeManager.guestList);
                            guestCountLabel.setText("Guests: " + attendeeManager.getGuestCount());
                        } else {
                            showAlert("Error", "Failed to add guest.");
                        }
                    });
                
            });
            
            // Button to remove selected guest
            Button removeGuestButton = new Button("Remove Selected Guest");
            removeGuestButton.setOnAction(event -> {
                String selectedGuest = guestListView.getSelectionModel().getSelectedItem();
                if (selectedGuest != null) {
                    attendeeManager.guestList.remove(selectedGuest);
                    attendeeManager.currentGuestCount--;  // Decrease count when guest is removed
                    guestListView.getItems().clear();
                    guestListView.getItems().addAll(attendeeManager.guestList);
                    guestCountLabel.setText("Guests: " + attendeeManager.getGuestCount());
                } else {
                    showAlert("No Guest Selected", "Please select a guest to remove.");
                }
            });
        
            Button backButtonGuest = new Button("Back");
            backButtonGuest.setOnAction(event -> primaryStage.setScene(createEventScene));
        
            guestLayout.getChildren().addAll(new Label("Manage Guests"), guestListView, addNewGuestButton, removeGuestButton, backButtonGuest);
            Scene guestManagementScene = new Scene(guestLayout, 400, 400);
            primaryStage.setScene(guestManagementScene);
        });
        
        //food items
        addFoodButton.setOnAction(e -> {
            VBox foodLayout = new VBox(10);
            ListView<String> foodListView = new ListView<>();
            Label foodCountLabel = new Label("Food items: "+ food.getFoodCount());
            foodLayout.getChildren().add(foodCountLabel);
            foodListView.getItems().addAll(food.foodList);
            
            // Button to add new food
            Button addNewFoodButton = new Button("Add Food");
            addNewFoodButton.setOnAction(event -> {
                
                    TextInputDialog dialog = new TextInputDialog();
                    dialog.setTitle("Add Food");
                    dialog.setHeaderText("Enter food name:");
                    dialog.showAndWait().ifPresent(foodName -> {
                        if (food.addFood(foodName)) {
                            foodListView.getItems().clear();
                            foodListView.getItems().addAll(food.foodList);
                            foodCountLabel.setText("Food items: " + food.getFoodCount());
                        } else {
                            showAlert("Error", "Failed to add food item.");
                        }
                    });
                
            });
            
            // Button to remove selected food
            Button removeFoodButton = new Button("Remove Selected Food item");
            removeFoodButton.setOnAction(event -> {
                String selectedFood = foodListView.getSelectionModel().getSelectedItem();
                if (selectedFood != null) {
                    food.foodList.remove(selectedFood);
                    food.currentFoodCount--;  // Decrease count when food item is removed
                    foodListView.getItems().clear();
                    foodListView.getItems().addAll(food.foodList);
                    foodCountLabel.setText("Food items: " + food.getFoodCount());
                } else {
                    showAlert("No Food item Selected", "Please select a food item to remove.");
                }
            });
            
        
            Button backButtonFood = new Button("Back");
            backButtonFood.setOnAction(event -> primaryStage.setScene(createEventScene));
        
            foodLayout.getChildren().addAll(new Label("Manage Food items"), foodListView, addNewFoodButton, removeFoodButton, backButtonFood);
            Scene foodManagementScene = new Scene(foodLayout, 400, 400);
            primaryStage.setScene(foodManagementScene);
        });
        
        

// To-Do List Management with Checkboxes
addToDoButton.setOnAction(e -> {
    VBox toDoLayout = new VBox(10);
    Label toDoLabel = new Label("To-Do List");

    // Checkbox list for each to-do item
    toDoCheckboxes = new VBox(5);
    for (String task : toDoList) {
        CheckBox taskCheckbox = new CheckBox(task);
        toDoCheckboxes.getChildren().add(taskCheckbox);
    }

    // Button to add a new task
    Button addTaskButton = new Button("Add Task");
    addTaskButton.setOnAction(event -> {
        TextInputDialog dialog = new TextInputDialog();
        dialog.setTitle("Add To-Do Item");
        dialog.setHeaderText("Enter to-do item:");
        dialog.showAndWait().ifPresent(toDoItem -> {
            toDoList.add(toDoItem);
            CheckBox newTaskCheckbox = new CheckBox(toDoItem);
            toDoCheckboxes.getChildren().add(newTaskCheckbox);
        });
    });
    

    // Button to return to main event creation screen
    Button backButton1 = new Button("Back");
    backButton1.setOnAction(event -> primaryStage.setScene(createEventScene));

    toDoLayout.getChildren().addAll(toDoLabel, toDoCheckboxes, addTaskButton, backButton1);
    Scene toDoScene = new Scene(toDoLayout, 400, 400);
    primaryStage.setScene(toDoScene);
});


        // Venue Selection
        setVenueButton.setOnAction(e -> {
            TextInputDialog dialog = new TextInputDialog();
            dialog.setTitle("Set Venue");
            dialog.setHeaderText("Enter venue name:");
            dialog.showAndWait().ifPresent(venue -> venueDecoration.setVenue(venue));
        });

        // Theme Selection
        setThemeButton.setOnAction(e -> {
            ChoiceDialog<String> themeDialog = new ChoiceDialog<>(venueDecoration.getAvailableThemes()[0], venueDecoration.getAvailableThemes());
            themeDialog.setTitle("Set Decoration Theme");
            themeDialog.setHeaderText("Choose a theme:");
            themeDialog.showAndWait().ifPresent(theme -> venueDecoration.selectTheme(theme));
        });

        saveEventButton.setOnAction(e -> {
            String eventName = eventNameField.getText();
            String date = dateField.getText();
            if (!eventName.isEmpty() && !date.isEmpty()) {
                Event newEvent = new Event(eventName, date, attendeeManager, food, venueDecoration, toDoList);
                currentUser.addEvent(newEvent); // Add event to the current user's event list
                updateHomeScene();
                //resetCreateEventScene();
                primaryStage.setScene(homeScene);
            } else {
                showAlert("Error", "Please enter both event name and date.");
            }
        });
        

        backButton.setOnAction(e -> primaryStage.setScene(homeScene));

        layout.getChildren().addAll(new Label("Event Name:"), eventNameField, new Label("Event Date:"), dateField, calendarLayout, addGuestButton, addFoodButton, setVenueButton, setThemeButton, addToDoButton, saveEventButton, backButton);
        createEventScene = new Scene(layout, 400, 400);
    }

    private void resetCreateEventScene() {
        eventNameField.clear();
        dateField.setText("select date");;
        datePicker.setValue(null);
        attendeeManager = new AttendeeManager();  // Reset the attendee manager
        food = new FoodManager();                // Reset the food manager
        venueDecoration = new VenueDecoration();  // Reset the venue decoration
        toDoList=new ArrayList<>();                         // Clear to-do list
    }
    

    // Show Event Details
    private void showEventDetails(Event event) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Event Details");
        alert.setHeaderText("Details for: " + event.getName());
        alert.setContentText(event.getDetails());
        DialogPane dialogPane = alert.getDialogPane();
        dialogPane.setPrefSize(800, 300);
        alert.showAndWait();
    }

    // Helper to show alerts
    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        DialogPane dialogPane = alert.getDialogPane();
        dialogPane.setPrefSize(500, 300);
        alert.showAndWait();
    }

    public static void main(String[] args) {
        launch(args);
    }

    // User Manager for login/register
    private static class UserManager {
        private HashMap<String, User> users = new HashMap<>();

        public boolean register(String username, String password) {
            if (users.containsKey(username)) return false;
            users.put(username, new User(username, password));
            return true;
        }

        public User login(String username, String password) {
            User user = users.get(username);
            return user != null && user.getPassword().equals(password) ? user : null;
        }
    }

    // User Class with events
    private static class User {
        private String username;
        private String password;
        private ArrayList<Event> events;

        public User(String username, String password) {
            this.username = username;
            this.password = password;
            this.events = new ArrayList<>();
        }

        public String getPassword() {
            return password;
        }

        public ArrayList<Event> getEvents() {
            return events;
        }

        public void addEvent(Event event) {
            events.add(event);
        }
    }

    // Event Class
    private static class Event {
        private String name;
        private String date;
        private AttendeeManager attendees;
        private FoodManager food;
        private VenueDecoration venueDecoration;
        private ArrayList<String> toDoList;

        public Event(String name, String date, AttendeeManager attendees, FoodManager food, VenueDecoration venueDecoration, ArrayList<String> toDoList) {
            this.name = name;
            this.date = date;
            this.attendees = attendees;
            this.food = food;
            this.venueDecoration = venueDecoration;
            this.toDoList = toDoList;
        }

        public String getName() {
            return name;
        }

        public String getDetails() {
            return "Date: " + date + "\n" +
                   "Guests: " + attendees.showGuestList() + "\n" +
                   "Food: " + food.showFoodList() + "\n" +
                   "Venue Decorations: " + venueDecoration.showVenueAndTheme() + "\n" +
                   "To-Do List: " + toDoList;
        }
    }
//attendee class
    private static class AttendeeManager {
        
        private ArrayList<String> guestList;
        private int currentGuestCount;  // New counter
    
        // Constructor with max guests argument
        public AttendeeManager() {
            
            this.guestList = new ArrayList<>();
            this.currentGuestCount = 0;  // Initialize counter
        }
    
        // Add guest method with max guests check
        public boolean addGuest(String guestName) {
                guestList.add(guestName);
                currentGuestCount++;  // Increment the counter
                return true;
            
        }
    
        // Show guest list
        public String showGuestList() {
            return "Guests (" + currentGuestCount  + "): " + String.join(", ", guestList);
        }
    
        // Get the current guest count
        public int getGuestCount() {
            return guestList.size();
        }
    }
    

 // Food Manager Class
 private static class FoodManager {
    private ArrayList<String> foodList;
    private int currentFoodCount;  // New counter

    // Constructor with max guests argument
    public FoodManager() {
        this.foodList = new ArrayList<>();
        this.currentFoodCount = 0;  // Initialize counter
    }

    // Add food method with max food check
    public boolean addFood(String foodName) {
            foodList.add(foodName);
            currentFoodCount++;  // Increment the counter
            return true;
    }

    // Show food list
    public String showFoodList() {
        return "Food items (" + currentFoodCount +  "): " + String.join(", ", foodList);
    }

    // Get the current food count
    public int getFoodCount() {
        return foodList.size();
    }
}


    // Venue Decoration Class
    private static class VenueDecoration {
        private String venue = "No venue selected";
        private String theme = "Default Theme";
        private String[] themes = {"Classic", "Modern", "Rustic","Simple","Other"};

        public void setVenue(String venue) {
            this.venue = venue;
        }

        public void selectTheme(String theme) {
            this.theme = theme;
        }

        public String[] getAvailableThemes() {
            return themes;
        }

        public String showVenueAndTheme() {
            return "Venue: " + venue + "\nTheme: " + theme;
        }
    }
    
}
