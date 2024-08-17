# ESP32 Web Server

## Table of Contents

- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Accessing Remotely](#accessing-remotely)
- [License](#license)

## Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) or PlatformIO for ESP32 firmware development
- [Node.js](https://nodejs.org/) for running the React application
- [Vite](https://vitejs.dev/) for development server
- [Tailwind CSS](https://tailwindcss.com/) for styling

## Installation


1. **Clone the repository**:
   ```
   git clone https://github.com/aaymecho/esp32-web-server
   cd esp32-web-server
   ```

2. **Setup Wifi Credentials (src/config.h)**

	```
	#ifndef CONFIG_H
	#define CONFIG_H

	const char* SSID = "WIFI_NAME";
	const char* PASSWORD = "WIFI_PASSWORD";

	#endif
```
