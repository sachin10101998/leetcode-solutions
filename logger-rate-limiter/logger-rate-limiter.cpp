class Logger {
public:
    map<string,int>m1;
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m1.find(message)==m1.end()){
            m1[message]=timestamp+10;
            return true;
        }
        else if(m1.find(message)!=m1.end()){
            int curr_max = m1[message];
            if(timestamp<curr_max){
                return false;
            } else {
                m1[message]=timestamp+10;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */