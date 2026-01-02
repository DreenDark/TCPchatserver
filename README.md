TCP Chat Server & Client (C)

A simple TCP-based chat application written in C, demonstrating the fundamentals of socket programming, client–server architecture, and TCP communication.

This project was built as a learning exercise to understand how networking works at a low level using the POSIX sockets API.

📌 Features
TCP-based communication (IPv4)
Separate server and client programs
User-provided destination IP on client side
Turn-based chat (send → receive loop)
Proper handling of:
sockets
ports and byte order
connection setup and teardown
Clean and readable C code

🧠 Concepts Covered
socket()
bind()
listen()
accept()
connect()
send() / recv()
struct sockaddr_in
Network byte order (htons)
Blocking I/O
Basic error handling

🗂 Project Structure
Copy code

.
├── server.c # TCP chat server
├── client.c # TCP chat client
└── README.md


💻 Installation
🔸 Requirements

Linux / Unix-based OS
GCC compiler
Basic knowledge of C

🔸 Steps

Clone or download the repository:

git clone https://github.com/DreenDark/TCPchatserver.git

cd TCPchatserver


🛠 Compilation
Compile the server and client separately:
Copy code
Bash
gcc server.c -o server
gcc client.c -o client


▶️ Usage
1️⃣ Start the server
On the server machine:
Copy code
Bash
./server
The server listens on port 8080.
2️⃣ Run the client
On the client machine (same device or different device on the network):
Copy code
Bash
./client
When prompted, enter the server’s IP address, for example:
Localhost (same machine):
Copy code

127.0.0.1
Local network:
Copy code

192.168.1.100
3️⃣ Chat
Client sends a message
Server responds
Communication continues in a loop until one side disconnects


🌐 Networking Notes
The server uses:
Copy code
C
INADDR_ANY
so it can accept connections on any network interface.
The client converts:
IP address using inet_addr()
Port using htons()
This program uses blocking sockets, so each side waits for the other to send data.


⚠️ Limitations
One client at a time
Turn-based communication (not simultaneous typing)
No encryption
No message framing beyond simple strings
These are intentional, to keep the project focused on fundamentals.


🚀 Future Improvements
Support multiple clients
Use threads or select() for full-duplex chat
Add message timestamps
Handle partial sends/receives
Add encryption (TLS or custom)


📚 Educational Purpose
This project is designed for learning and experimentation.
It is not intended for production use.

👤 Author
Amirreza
Built as part of a personal journey into systems programming, networking, and cybersecurity fundamentals.