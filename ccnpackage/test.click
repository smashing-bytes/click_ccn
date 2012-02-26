require(package "ccn");

//fib :: Forwarding;
//inthandler :: InterestHandler;
//classifier :: CCNClassifier;
//cs :: ContentStore;
//pit :: InterestTable;
daemon :: CCNDaemon;
//producer :: Producer;

Socket(UDP, 0.0.0.0, 5050) -> [0]daemon;
Socket(UDP, 0.0.0.0, 6060) -> [1]daemon;





