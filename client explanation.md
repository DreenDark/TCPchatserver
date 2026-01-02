This is the explanation of the client part of my project .

the first 5 lines are the required headers that the function s will use;
 we go part by part:

8-14
the os gives us an address represents the socket address , so we defined the sockfd int.
then in the socket() we get that value. the parametr of that is :
AF_INET= says the address is ipv4.
SOCK_STREAM= the connection comunication(TCP).
and 0 means use the TCP protocol.

16-24
we define an address for getting the destination IP so x gives the 16 caracter ip address(15 for address and one for \0) then we ommit the \n and after that make an struct that save the informations.
memset()clean the storage for the new values.
22:the family address that server has (IPV4)
23:says the outgoing port is 8080
24:save the destination address which came from x.

26-30
connect()says that the information from sockaddr struct goes through the sockfd with its size and if it fails returns -1 which means it not connected.

32-46
we defines the variables to save the values which recived or is sending.
send() says the message with its size go to the destination through sockfd.
recv is like the same.
