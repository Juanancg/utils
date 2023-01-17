# Basic Client Server application C++
Using boost
To compile it:

```sh
g++ Server.cpp -o server -L /usr/lib/ -lpthread -lboost_system
g++ Client.cpp -o client -L /usr/lib/ -lpthread -lboost_system
```