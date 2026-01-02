This is the explanation of the server part of my project .

the first 6 lines are the required headers that the function s will use;
 we go part by part:

The os gives you an integer number that represents the socket that called file descriptor so we define newsocket variable (int).

10-15
the socket() function asks the os that make a network communication endpoint for me .then the os :
allocates kernel resource.
creates internal socket structures.
return an integer id.
AF_INET means i want to use an ipv4 address.
SOCK_STREAM means connection-based communication (TCP) .
0 means choose default protocol for this type then os automatically choose TCP.
if the os cant make a socket it returns -1 which means connection failed other ways socket will creat successfully.

17-27
the structure describes where the socket should live in the network.the structure holds IP adress,port number,address family.
then we initialize memory with memset that make every bytes of the address structure zero .
19:this address belongs to ipv4.
20:this program will use port 8080.htons()make a network byte order
21:this says accept connection from any network interfaces like wifi,lan localhost... .
then the bind() means associate my socket with this ip address and port.befor bind socket exist  but has no address after that the os knows which part this socket owns and which ip it listens on .

30-35
listen() means turn this soket into listening socket.
now the socket cannot send or recive data directly and only wait for incomming connections.the number 4 means allow up to 4 clients to wait in line .

37-47
new socket listening socket and client socket is communication socket.when client connects the os creates a new socket return its file descriptor accept() gives it to you.
this allows server to keep listening and talks to the client seperatly.

49-66
nake some arrays for sending and reciving data .then with memset() we erase the memory in size of that .the bytes recive the recv() function recive the input into the buffer.the send() function will send the massage saved in its array to the client.

short explain:
socket():creat communication endpoint.
bind():give it an address.
lisen():waits for connection.
accept():creates client connection.
recv()/send():exchange data.
