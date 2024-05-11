#include<iostream>
using namespace std;

class Tweets{
	int tweetId=0;
	string content;
	string **reply;
	int totalLikes;
	int customerId;
	public:
		Tweets(){
		}
		Tweets(string content,int userId){
			reply=new string*[20];
			for(int i=0;i<20;i++){
				reply[i]=new string[20];
			}
			this->customerId=userId;
			this->tweetId++;
			this->totalLikes=0;
			this->content=content;
		}
	setContent(string tweet){
		content=tweet;
	}
	string getContent(){
		return content;
	}
	int getCustomerId(){
		return customerId;
	}
	int getTweetId(){
		return tweetId;
	}
	setTotalLikes(){
		this->totalLikes++;
	}
	int getTotalLikes(){
		return totalLikes;
	}

};

class Reply{
	int replyId=0;
	string comment;
	int tweetId;
	public:
		Reply(){
		}
	Reply(string com,int id){
		this->comment=com;
		this->tweetId=id;
		this->replyId++;
	}
	
	int getReplyId(){
		return replyId;
	}
	string getContent(){
		return comment;
	}
	int getTweetId(){
		return tweetId;
	}
	
};
Tweets availableTweets[20];
Reply availableReply[20];
int totalTweets=0,totalReply=0;
int Uid=1,chId=1;
class ChatBox{
	int chatId;
	string chatContent;
	int fromUserId;
	int toUserId;
	
	public:
	ChatBox(){
		
	}
	ChatBox(string message,int from,int to){
		this->chatContent=message;
		this->fromUserId=from;
		this->toUserId=to;
	}
	setChatContent(string content){
		this->chatContent=content;
		this->chatId=chId++;;
	}
	string getChatContent(){
		return chatContent;
	}
	getChatId(){
		return chatId;
	}
	setFromUserId(int idd){
		this->fromUserId=idd;
	}
	int getFromUserId(){
		return fromUserId;
	}
	setToUserId(int idd){
		this->toUserId=idd;
	}
	int getToUserId(){
		return toUserId;
	}
};
ChatBox availableChats[20];
int totalChats=0;
class User{
//	int id=0;
	int userId;
     string Name;
	 int Age;
	 string Gender;
	 string Dob;
	 string Password;
	 int totalTweets;
//	 Tweets tweet[20];
	 public:
	 	User(){
	 		
		 }
	 string getPassword() {
		return Password;
	}
	void setPassword(string password) {
		Password = password;
		
	}
    string getName() {
		return Name;
	}
	void setName(string name) {
		Name = name;
	
//		this->totalTweets=0;
	}
	int getAge() {
		return Age;
	}
    void setAge(int age) {
		Age = age;
	}
	string getGender() {
		return Gender;
	}
	void setGender(string gender) {
		Gender = gender;
			this->userId=Uid;
		Uid++;
		cout<<"sbs "<<this->userId<<"  "<<" "<<Uid<<endl;
	}
	string getDob() {
		return Dob;
	}
	void setDob(string dob) {
		Dob = dob;
	}
//	setTweets(Tweets message){
//		this->tweet[this->totalTweets++]=message;
//		cout<<tweet[this->totalTweets-1].getContent()<<" count  "<<this->totalTweets<<endl;
////		this->totalTweets+=1;
//	}
	int getTotalTweets(){
//		cout<<this->totalTweets<<endl;
		return totalTweets;
	}
	setTotalTweets(){
		this->totalTweets++;
	}
	
	int getUserId(){
		return userId;
	}
	
};
User customerDetails[20];
int totalCustomer=0;
class UserUtil{
	public:
	User findUser( string name)	{
		User customer;
        customer.setName(" ");
		for(int i=0;i<totalCustomer;i++)
		{
			string checkName = customerDetails[i].getName();
			if(checkName==name)
			{
				customer = (User) customerDetails[i];
				break;
			}
		}
		return customer;
    }
		
	void registerDetails()
	{

		User data;
		string name;
		cout<<"ENTER NAME"<<endl;
		cin>>name;
		data.setName(name);
		int age;
		cout<<"ENTER AGE"<<endl;
		cin>>age;
		data.setAge(age);
		string gender;
		cout<<"ENTER GENDER"<<endl;
		cin>>gender;
		data.setGender(gender);
		string dob;
		cout<<"ENTER DOB"<<endl;
		cin>>dob;
		data.setDob(dob);
		customerDetails[totalCustomer]=data;
		totalCustomer++;
	}
	void postTweet(User &currentCustomer){
		cout<<"Enter Your Tweet"<<endl;
		string tweet;
		cin.ignore();
		getline(cin,tweet);
		Tweets addTweet(tweet,currentCustomer.getUserId());
		availableTweets[totalTweets++]=addTweet;
	}
	
	void displayTweet(){
		int cnt=1;
//		cout<<currentCustomer.getTotalTweets()<<endl;
		for(int i=0;i<totalTweets;i++){
			cout<<cnt++<<" "<<availableTweets[i].getContent()<<endl;
		}
	}
	
	void deleteTweet(User &currentCustomer){
		int cnt=1;
//		cout<<currentCustomer.getTotalTweets()<<endl;
		int tweetId[20];
		int totalId=0;
		for(int i=0;i<totalTweets;i++){
			if(availableTweets[i].getCustomerId()==currentCustomer.getUserId()){
				tweetId[totalId++]=availableTweets[i].getTweetId();
			cout<<cnt++<<" "<<availableTweets[i].getContent()<<endl;
			}
		}
		cout<<"Enter Any Index To Delete"<<endl;
		int ind;
		cin>>ind;
		for(int i=0;i<totalTweets;i++){
			if(availableTweets[i].getTweetId()==tweetId[ind-1]){
				for(int j=i;j<totalTweets-1;j++){
					availableTweets[j]=availableTweets[j+1];
				}
				break;
			}
		}
		totalTweets--;
	}
	
	seeTweets(User &currentCustomer){
//		Tweets availableTweets[20];
		int id[20];
		int totalId=0;
		int cnt=1;
		cout<<"Select any User name to see their tweets"<<endl;
		for(int i=0;i<totalCustomer;i++){
				cout<<cnt++<<" "<<customerDetails[i].getName()<<endl;
				id[totalId]=customerDetails[i].getUserId();
				cout<<"id "<<id[totalId]<<endl;
				totalId++;
		}
//		cout<<"Select Any Index To add Reply or Like"<<endl;
		int ind;
		cin>>ind;
		int tweetId[20];
		totalId=0;
		cnt=1;
		for(int i=0;i<totalTweets;i++){
			if(availableTweets[i].getCustomerId()==id[ind-1]){
				tweetId[totalId++]=availableTweets[i].getTweetId();
				cout<<cnt++<<" "<<availableTweets[i].getContent()<<endl;
			}
		}
		cout<<"Enter Any Index to See the Tweet"<<endl;
		cin>>ind;
		for(int i=0;i<totalTweets;i++){
			if(availableTweets[i].getTweetId()==tweetId[ind-1]){
				cout<<availableTweets[i].getContent()<<endl;
				cout<<endl;
				for(int j=0;j<totalReply;j++){
					if(availableReply[j].getTweetId()==availableTweets[i].getTweetId()){
						cout<<cnt++<<" "<<availableReply[i].getContent()<<endl;
					}
				}
				cout<<"1.Like 2.Reply 3.TotalLikes 4.Exit"<<endl;
				int op;
				cin>>op;
				if(op==1){
					availableTweets[i].setTotalLikes();
				}
				else if(op==2){
					cout<<"Type Your Comment"<<endl;
					string com;
					cin.ignore();
					getline(cin,com);
					Reply addReply(com,availableTweets[i].getTweetId());
					availableReply[totalReply++]=addReply;	
				}
				else if(op==3){
					cout<<availableTweets[i].getTotalLikes();
				}
				else{
					break;
				}
			}
		}
		
	}
	chat(User currentUser){
		int id[20];
		int totalId=0;
		string name[20];
		int totalName=0;
		int cnt=1;
		cout<<"Select any User name to See Chat"<<endl;
		for(int i=0;i<totalCustomer;i++){
				cout<<cnt++<<" "<<customerDetails[i].getName()<<endl;
				id[totalId]=customerDetails[i].getUserId();
				name[totalName]=customerDetails[i].getName();
//				cout<<"id "<<id[totalId]<<endl;
				totalId++;
				totalName++;
		}
		int ind;
		cin>>ind;
		for(int i=0;i<totalChats;i++){
			if(availableChats[i].getFromUserId()==currentUser.getUserId() && availableChats[i].getToUserId()==id[ind-1]){
				cout<<currentUser.getName()<<"  -  "<<availableChats[i].getChatContent()<<endl;
			}
			else if(availableChats[i].getFromUserId()==id[ind-1] && availableChats[i].getToUserId()==currentUser.getUserId()){
				cout<<name[ind-1]<<"  -  "<<availableChats[i].getChatContent()<<endl;
			}
		}
		cout<<"Enter Your Message to Chat With "<<customerDetails[ind-1].getName()<<endl;
		string message;
		cin.ignore();
		getline(cin,message);
		ChatBox chat(message,currentUser.getUserId(),customerDetails[ind-1].getUserId());
		availableChats[totalChats++]=chat;	
	}
};



int main(){
	int selectedOperation;

					do {

						 cout<<"CHOOSE OPERATIONS "<<endl;
                         cout<<"1.LOGIN"<<endl;
                         cout<<"2.REGISTER"<<endl;
                         cout<<"3.EXIT"<<endl;
						UserUtil customerUtil;
						User currentCustomer;
						currentCustomer.setName(" ");
						//Customer *check=&currentCustomer;
						//check=NULL;
						cin>>selectedOperation;
						switch(selectedOperation)
						{
						case 1:{
                            int set=0;
							do {

							string name;
							cout<<"ENTER NAME     "<<endl;
							cin.ignore();
							getline(cin,name);

							string password;
							cout<<"ENTER PASSWORD"<<endl;
							cin>>password;

							currentCustomer = customerUtil.findUser(name);
							if(currentCustomer.getName()==" ")
								cout<<"ENTER VALID USERNAME"<<endl;
							}while(currentCustomer.getName()==" ");
						

						int ticketMethods;
							do{
							
							
								cout<<"CHOOSE OPERATIONS";
								cout<<"1. Post Tweet"<<endl;
								cout<<"2.See Yout Tweet"<<endl;
								cout<<"3. Delete Tweet"<<endl;
								cout<<"4. Liked Tweet"<<endl;
								cout<<"5. See Others Tweet"<<endl;
								cout<<"6.Chat With Users"<<endl;
								cout<<"7. EXIT"<<endl;
								cin>> ticketMethods;
								User customer;
								UserUtil customerUtil1;
								switch(ticketMethods)
								{
								case 1:
									customerUtil1.postTweet(currentCustomer);
									break;
								case 2 :
								    customerUtil1.displayTweet();
									break;
								case 3 :
									customerUtil.deleteTweet(currentCustomer);
									break;
								case 4 :
//								    customerUtil1.cancelCart(currentCustomer);
									break;
                                case 5:
                                	customerUtil1.seeTweets(currentCustomer);
                                    break;   
                                case 6:
                                	 customerUtil1.chat(currentCustomer);
								default:
									break;
								}
							}while(ticketMethods!=7);
							break;
						}
					
						case 2:
							customerUtil.registerDetails();
							break;
						case 3:
							break;
						}

					}while(selectedOperation != 3);



}
