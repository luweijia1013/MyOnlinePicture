#include <iostream>
#include <string>
using namespace std;

//玩家剩余的包裹数目
const int spaceNum = 0;
//玩家包裹里水晶的数目
const int cryNum = 1;

//宝石的道具ID 
const int gemID = 799;
//水晶的道具ID 
const int crystalID = 800;

/**
 * \brief 发送提示给玩家
 * @test 提示的内容
 */
void sendTestToUser(const string &test)
{
	cout << test << endl;
}

/**
 * \brief 写日志到文件，以便查询相关错误日志信息
 * @log 日志的内容
 */
void writeLog(const string &log)
{
	cout << "log:" << log << endl; 
}

/**
 * \brief 玩家的包裹类
 */
struct package
{
	/**
	 * \brief 获取包裹剩余空间
	 * @return 包裹剩余空间数目
	 */
	int getSpaceNum(){ return spaceNum;}

	/**
	 * \brief 添加道具进包裹
	 * @itemID 道具ID
	 * @itemNum 道具数目
	 * @return 道具是否添加成功
	 */
	bool addItem(int itemID,int itemNum)
	{
		//中间有很长的代码，可能会返回false;
		sendTestToUser("添加道具成功");
		return true;
	}

	/**
	 * \brief 从包裹里扣除道具
	 * @itemID 道具ID
	 * @return 道具是否扣除成功
	 */
	bool removeItem(int itemID)
	{
		//中间有很长的代码，可能会返回false;
		return true;	
	}
	
	/**
	 * \brief 从包裹里扣除道具
	 * @itemID 道具ID
	 * @return 道具是否扣除成功
	 */
	int getItemNum(int itemID)
	{
		if (itemID == crystalID)
			return cryNum;
		return 0;
	}
};

/**
 * \brief 玩家类
 */
struct user
{
	package pack;	
};
int main()
{
	//括号以内代码模拟 客户端消息发送到服务器解包以后，服务器处理逻辑的流程 返回0表示这个消息的处理逻辑结束 
	/* 添加道具
	 * forExample
	 * user m_user;
         * m_user.addItem(1,1);
	 */
	{
	}
	return 0;
}

