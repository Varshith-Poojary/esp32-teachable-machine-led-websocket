# esp32-teachable-machine-led-websocket
This repository contains a project that integrates an ESP32 microcontroller with Teachable Machine for voice command recognition and WebSocket communication to control an LED based on detected commands.

# Project Structure

```plaintext
my_project/
│
├── server
│   └── <filename>.ino   # ESP32 code
├── node_modules
├── index.html           # Web client for interaction
├── package-lock.json    # Automatically generated; locks dependencies
├── package.json         # Project metadata and dependencies
└── my_model/
    ├── model.json       # Teachable Machine model file
    └── metadata.json    # Teachable Machine metadata file
```

## Setup Instructions

### 1. Upload ESP32 Code

- Navigate to the `server` directory.
- Open the `<filename>.ino` file in the Arduino IDE.
- Upload the code to your ESP32 microcontroller.

### 2. Initialize the Node.js Project

If you haven’t already initialized your Node.js project, run the following command:

```bash
npm init -y
```
### 3. Install Required Packages

You need the `http-server` package to serve your files. Install it using npm:

```bash
npm install http-server --save-dev
```

### 4. `index.html`

Ensure your `index.html` is properly set up to load the Teachable Machine model. The provided `index.html` file should be sufficient for this.

### 5. Teachable Machine Model

Make sure the `my_model/` directory contains `model.json` and `metadata.json` downloaded from Teachable Machine. These files are necessary for your Teachable Machine model.

## Run the Project

1. Upload the ESP32 code to the ESP32.

2. Connect the ESP32 to the same network as the device running the `index.html` code.

3. Start the web server:

    - **Using Live Server Extension:** Click on "Go Live" in your code editor.
    
    - **Or via Command Line:** Run the following command in CMD to start the server:
    
      ```bash
      npx http-server -p 5500
      ```

4. Open your web browser and go to:
   
   ```arduino
   http://localhost:5500



