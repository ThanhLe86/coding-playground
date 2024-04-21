import java.util.LinkedList;
class BrowserHistory {

    LinkedList<String> BrowserHistory = new LinkedList<>();
    int current_iterator = 0;
    public BrowserHistory(String homepage) {
        BrowserHistory.add(homepage);
    }
    
    public void visit(String url) {
        BrowserHistory.add(url);
        current_iterator++;   
    }
    
    public String back(int steps) {
        String res = new String();
        if(steps < current_iterator)
        {
            current_iterator -= steps;
            res = BrowserHistory.get(current_iterator);
        } else {
            res = BrowserHistory.get(0);
            current_iterator = 0;
        }

        return res;
    }
    
    public String forward(int steps) {
        String res = new String();
        current_iterator += steps;
        if(current_iterator > BrowserHistory.size() - 1)
        {
            current_iterator = BrowserHistory.size() - 1;
            res = BrowserHistory.get(current_iterator);
        } else res = BrowserHistory.get(current_iterator);
        return res;
    }
}
