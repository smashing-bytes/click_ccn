require(package "ccn");

fib :: Forwarding;
producer :: Producer
inthandler :: InterestHandler;
classifier :: CCNClassifier;
cs :: ContentStore;
pit :: InterestTable;

producer[0] -> classifier;
classifier[0] -> inthandler;
classifier[1] -> cs;
cs[0] -> [1]pit;
inthandler[0] -> [0]pit;
pit[0] -> [0]fib;
fib[0] -> [2]pit;




