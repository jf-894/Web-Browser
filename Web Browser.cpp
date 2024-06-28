//Jordan Fernandez
//CWID:885780551

#include<iostream>
#include<memory>
#include<vector>
#include<string>

// Write template class Tab here
 class Tab {
    public:
    Tab(){};
    Tab(std::string u, std::string n, double m) {
        url = u;
        name = n;
        memory = m;
    }
    //Member Variables
    std::string url;
    std::string name;
    double memory;
    Tab* next;
    Tab* prev;
};
// Write template class Browser here
template <typename T> class Browser {
    public:
    Browser() {
   head_ = nullptr;
   tail = nullptr;
   current_ = nullptr;
}
    //Member Functions 
    void addNewTab(std::string ur, std::string nam, double mem) {
        Tab* new_node = new Tab(ur,nam,mem);
        if (head_ == nullptr){
            new_node->url = ur;
            new_node->name = nam;
            new_node->memory = mem;
            new_node->prev = nullptr;
            new_node->next = nullptr;
            head_ = new_node;
            tail = new_node;
            current_ = new_node;
        }
        else {
            new_node->url = ur;
            new_node->name = nam;
            new_node->memory = mem;
            new_node->next = nullptr;
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
            current_ = new_node;
        }
        

}
    void switchToPrevTab(){
        if(current_->prev == nullptr){
            std::cout << "No previous tab" << std::endl;
            std::cout<<std::endl;
        }
        else {
             std::cout << current_->prev->url<<std::endl;
             std::cout << current_->prev->name<<std::endl;
             std::cout << current_->prev->memory<<std::endl;
             std::cout<<std::endl;
             current_ = current_->prev;
        }
    }
    void switchToNextTab(){
        if(current_->next == nullptr){
            std::cout<< "No next tab"<<std::endl;
            std::cout<<std::endl;
        }
        else {
            std::cout << current_->next->url<<std::endl;
            std::cout << current_->next->name<<std::endl;
            std::cout << current_->next->memory<<std::endl;
            std::cout<<std::endl;
            current_ = current_->next;
        }
    }
    void closeCurrentTab(){
        if (head_ == nullptr)
        {
            throw "No tabs";
        }
        
        else if(current_ == tail){
            tail->prev->next = nullptr;
            tail = tail->prev;
            current_ = tail;
        }
        else if (current_ == head_){
            head_->next->prev = nullptr;
            head_ = head_->next;
            current_ = head_;
        }
        else{
            current_->prev->next = current_ ->next;
            current_->next->prev = current_ ->prev;
            
        }
        
        
    
    }
    void bookmarkCurrent(){
        if(bookmark.size() == 0){
    bookmark.push_back(std::make_pair(current_->name, tail->url));
        } else if (bookmark.size()> 0) {
            for (int i = 0; i < bookmark.size(); i++){
                if(bookmark.at(i).first == current_->name && bookmark.at(i).second == current_->url){
                    std::cout <<"The bookmark is already added!!"<<std::endl;
                } else {
                    bookmark.push_back(std::make_pair(current_->name, current_->url));
                    break;
                }
            }

        }
    
   }
    void showBookmarkTab(){
        std::cout << "Bookmarks :" <<std::endl;
       for(int i = 0; i < bookmark.size(); i++){ 
        std::cout << bookmark.at(i).first;
        std::cout <<"(" << bookmark.at(i).second << ")"<<std::endl;
       }
    }
    void moveCurrentToFirst(){
        if(head_ == nullptr){
            throw "No tabs open";
        }
        else if (current_ == tail){
            tail->prev->next = nullptr;
            head_->prev = tail;
            tail->next = head_;
            head_ = tail;
            head_->prev = nullptr;
            tail = tail->prev;
            current_ = head_;

            // Moves tail to front
            /*
            head_->prev = tail->next;
            tail->next = head_;
            tail->next = nullptr;
             //New Tail
            tail = tail->prev;
            
            //
            current_ = head_;
            head_ = tail;
            */
        }
        else{

            current_->prev->next = current_->next;

            //head_->prev = current_->next;
            current_->next = head_;
            head_ = current_;

        
        }
        std::cout << "Now the current tab = "<< std::endl;
        auto curr = head_;
        while(curr) {
        std::cout<<"| "<<curr->name<<" x|-->";
        curr = curr->next;
    }
     std::cout << std::endl;
}
    double total_memory(){
        auto curr = head_;
        double total_mem;
        while(curr) {
        total_mem += curr->memory;
        curr = curr->next;
    }
        return total_mem;
    }
    void deleteTab(){
       double mem = head_->memory;
       auto test = head_;
       while(test) {
        if (mem < test->memory){
            mem = test->memory;
            test->prev->next = test->next;
            
            std::cout << "Deleted element = " << test->name << " with memory size = "<< mem<<std::endl;
        }
        test = test->next;
       }
    };
    void display(){
        auto curr = head_;
        std::cout<<"Browser tab list = "<<std::endl;
            while(curr){
            std::cout<<"| "<<curr->name<<" x|-->";
            curr = curr->next;
        }
            std::cout<<std::endl;
            std::cout<<std::endl;
}
    //Members Variables
    Tab* head_;
    Tab* tail;
    Tab* current_;
    std::vector<std::pair<std::string,std::string>> bookmark;

};
int main(){
/*Browser<double> b1;
b1.addNewTab("https://www.google.com","Google",23.45);
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to Next tab = "<<std::endl;
b1.switchToNextTab();
b1.addNewTab("https://www.youtube.com","YouTube",56);
b1.bookmarkCurrent();
b1.display();
b1.addNewTab("https://www.geeksforgeeks.com","GeeksForGeeks",45.78);
b1.bookmarkCurrent();
b1.addNewTab("https://chat.openai.com","ChatGPT",129);
b1.addNewTab("https://linkedin.com","LinkedIn",410);
b1.bookmarkCurrent();
b1.addNewTab("https://github.com","Github",110);
b1.addNewTab("https://kaggle.com","Kaggle",310);
b1.bookmarkCurrent();
b1.display();
std::cout<<"Total memory consumption = "<<b1.total_memory()<<"MB"<<std::endl;
b1.showBookmarkTab();
b1.moveCurrentToFirst();
b1.display();
b1.deleteTab();
b1.display();
std::cout<<"Switch to next tab = "<<std::endl;
b1.switchToNextTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.closeCurrentTab();
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.closeCurrentTab();
b1.display();
b1.showBookmarkTab();
std::cout<<"Total Memory Consumption = "<<b1.total_memory()<<"MB"<<std::endl;
b1.deleteTab();
b1.display();
b1.addNewTab("https://docs.google.com/","Google Docs",102.34);
b1.display();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
std::cout<<"Switch to previous tab = "<<std::endl;
b1.switchToPrevTab();
b1.bookmarkCurrent();
b1.showBookmarkTab();
b1.total_memory();
b1.deleteTab();
b1.display();*/
return 0;
}