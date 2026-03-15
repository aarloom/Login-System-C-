# Login System (C++)

This is a small C++ project I built while learning file input/output and string handling. The program allows a user to register a username and password and then log in using credentials stored in a text file.

The goal of this project was to practice working with files, user input, and basic validation logic.

## Features

* Register a new user
* Login using saved credentials
* Password validation:

  * minimum 8 characters
  * must contain uppercase and lowercase letters
  * must contain at least one number
  * no spaces allowed
* Credentials are stored in a text file (`users.txt`)

## Files

`login_system.cpp`
Main C++ source file containing the login system program.

`users.txt`
Stores usernames and passwords entered during registration.

`README.md`
Project description.

## Example Run

```
Welcome to the Login System!
1. Register
2. Login
3. Exit
Please select an option: 1

Enter a username: alex
Enter a password: password
Password must contain at least one uppercase letter. Please try again: Password1

Registration successful!
```

Login example:

```
Enter your username: alex
Enter your password: Password1

Login successful!
```

## What I Practiced

* file input/output (`ifstream` / `ofstream`)
* loops and conditionals
* string processing
* building a simple menu system
* basic password validation

## Possible Improvements

Some things I might add later:

* prevent duplicate usernames
* limit login attempts
* hide password input
* encrypt stored passwords


