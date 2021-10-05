class Logger {
public:
    map<string, int> m1;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(m1.find(message)==m1.end()){
            m1[message]=timestamp;
            return true;
        } else{
            int last_timestamp = m1[message];
            if(timestamp-last_timestamp>=10){
                m1[message]=timestamp;
                return true;
            } else{
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */