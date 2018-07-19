#pragma once
#include <string>
#include <vector>
#include <set>

struct Message
{
	int userIP;
	std::string text;
};

class Server
{
public:
	Server();
	~Server();

	void new_day();
	void send_message(Message m);
private:
	
	class User
	{
	public:
		User(int ip);

		int IP;
		bool spam() const;
		bool operator<(const User& other) { return this->IP < other.IP; }
		bool operator==(const User& other) { return this->IP == other.IP; }
		bool operator==(const int& other) { return this->IP == other; }
		mutable int messages_per_days[5] = {0};
	};

	struct UsersComp
	{
		bool operator()(const Server::User& lhs, const Server::User& rhs) const
		{
			return lhs.IP < rhs.IP;
		}
	};

	std::vector<Message> messages;
	std::set<User, UsersComp> users;
};

