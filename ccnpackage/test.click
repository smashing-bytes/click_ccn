require(package "ccn");

queue:: Queue;
fwd :: Forwarding;
pit :: InterestHandler;

FromDevice(eth0)-> queue -> fwd -> pit;


