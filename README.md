# Bank System 

Console Application: Financial Management System
This document describes a console-based application designed to manage clients, track financial transactions, handle user accounts, and provide currency-related utilities. It's a text-based interface, making it suitable for environments where a graphical user interface is not available or preferred. The application is structured around a main menu, providing access to various functional modules.

Main Menu Options:
## The application presents a main menu upon successful login, offering the following options:

### Client Management: This module allows for managing client information.

Show Client List: Displays a list of all registered clients, typically including their name, ID, and potentially a summary of their balance.

Add Client: Allows a new client to be registered in the system by entering their details.

Delete Client: Removes an existing client from the system based on their identifier.

Find Client: Searches for a specific client using criteria such as name or ID and displays their details.

### Transactions: This is the core financial module, handling various types of transactions for clients.

Deposit: Records a deposit of funds into a client's account.

Withdraw: Records a withdrawal of funds from a client's account, likely including checks for sufficient balance.

Total Balance: Displays the current total balance for a specific client or perhaps a summary of all client balances.

Transform (Transfer): Facilitates transferring funds between two different client accounts.

Register (Transaction Log): Allows viewing a log or history of transactions for a specific client or across the system.

Main Menu Log: Returns the user to the main application menu.

###Manage User: This section is for administrative tasks related to application users.

Functionality here would typically include adding new users, deleting users, modifying user permissions, or resetting passwords for users who access the console application itself.

User Permissions: The system incorporates a user permission model to control access to different features. This allows administrators to define roles or assign specific permissions to users, determining which menus, options (like deleting clients or updating currency rates), or data they can access and modify. This ensures data security and prevents unauthorized operations.

Login/Register: This is the initial entry point for users.

Login: Allows existing users to authenticate and gain access to the application's features. Requires username and password.

Register: Allows new users to create an account to access the application. This might be restricted to administrators depending on the system's design.

Currency Menu: Provides tools and information related to different currencies.

Show Currency List: Displays a list of supported currencies and their current exchange rates.

Find Currency: Allows searching for details of a specific currency.

Update Rate: Enables updating the exchange rate for a particular currency (likely an administrator function, controlled by user permissions).

Currency Calculator: Provides a utility to convert amounts between different currencies based on the stored rates.

Main Menu: Returns the user to the main application menu.

Log Out: Exits the current user session and typically returns to the Login/Register screen.

This console application provides a structured way to manage client data and financial operations through a clear, menu-driven interface, with user permissions ensuring secure and controlled access to its features.
