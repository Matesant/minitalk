# Minitalk

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>
    <div class="header-container">
        <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/covers/cover-minitalk-bonus.png" width="400" alt="Imagem 1"/>
        <img src="https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExOW1maGpoOGxpM3N5c2o5eDNqMmtteWtta202dDUzNWJpaG1jaHlvYiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/3o6Mbfsf4DI4Cds5Ms/giphy.webp" width="265" alt="Imagem 2"/>
    </div>
</body>
</html>


<h1 align="center">Send your messages! </h1>

## About
The goal of this project is to create a communication system that utilizes Unix signals for inter-process communication.
This involves implementing mechanisms to send and receive signals between processes, 
allowing them to coordinate and exchange information effectively.

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling**

To compile, go to the project path and run:

```shell
$ make
```


## 📋 Testing

To test the program you just need to launch the "server" and the "client" in different shell tabs with the following:

```shell
$ ./server
```

This will show your PID to make the client work and will stay waiting to receive a message from the "client"

```shell
$ ./client "PID" "Your message string"
```

By launching it, this will show "Your message string" on the server window.

## BONUS

The bonus functionality operates similarly to the mandatory features, with the key difference being that the client confirms the receipt of messages sent by the server.

```shell
$ ./server_bonus
```

```shell
$ ./client_bonus "PID" "Your message string"
```
