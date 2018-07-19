#include "stdafx.h"
#include "Server.h"




Server::Server()
{
}


Server::~Server()
{
}

void Server::new_day()
{

	for (std::set<User>::iterator it = users.begin(); it != users.end(); ++it)
	{

		for (int i = 4; i > 0; i--)
		{
			it->messages_per_days[i] = it->messages_per_days[i - 1];
		}
		it->messages_per_days[0] = 0;
	}
}

void Server::send_message(Message m)
{
	users.insert(m.userIP);
	auto sender = users.find(m.userIP);
	sender->messages_per_days[0]++;
	if (!sender->spam()) messages.push_back(m);
}

Server::User::User(int ip):
	IP(ip)
{}

bool Server::User::spam() const
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += messages_per_days[i];
	}
	return sum > 100;
}

