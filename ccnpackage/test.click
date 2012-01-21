require(package "ccn");

fib :: Forwarding;
inthandler :: InterestHandler;
classifier :: CCNClassifier;
cs :: ContentStore;
pit :: InterestTable;
daemon :: CCNDaemon;
producer :: Producer;

//Socket(TCP, 0.0.0.0, 5050) -> daemon;

producer -> inthandler;




