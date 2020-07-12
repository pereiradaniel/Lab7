#include <iostream>
#include <occi.h>		// To connect and work with databases in Oracle server.

using oracle::occi::Environment;
using oracle::occi::Connection;
using namespace oracle::occi;
using namespace std;

int main(void)
{
	// OCCI variables
	Environment* env = nullptr;
	Connection* conn = nullptr;

	// User Variables
	string str;
	string usr = "";		// this is your login assigned to you
	string pass = "";		// this is your password assigned to you
	string srv = "myoracle12c.senecacollege.ca:1521/oracle12c";

	try
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(usr, pass, srv);
		cout << "Connection is Successful!" << endl;
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}
	catch (SQLException& sqlExcp)
	{
		cout << sqlExcp.getErrorCode() << ": " << sqlExcp.getMessage();
	}
	return 0;
}