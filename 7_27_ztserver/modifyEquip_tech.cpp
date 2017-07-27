#include <iostream>
#include <string>
#include<map>
using namespace std;

//玩家剩余的包裹数目
const int spaceNum = 10;
//玩家包裹里水晶的数目
const int cryNum = 1;

//宝石的道具ID 
const int gemID = 799;
//水晶的道具ID 
const int crystalID = 800;
//小火龙的道具ID 
const int smallDragonID = 888;

/**
 * \brief 发送提示给玩家
 * @test 提示的内容
 */
void sendTextToUser(const string &text)
{
	cout << text << endl;
}

/**
 * \brief 写日志到文件，以便查询相关错误日志信息
 * @log 日志的内容
 */
void writeLog(const string &log)
{
	cout << "log:" << log << endl; 
}

struct exchangeGem_CS
{
	exchangeGem_CS()
	{
		objThisIDA = 0;
		objThisIDB = 0;
	}
	int objThisIDA;//道具A的唯一ID
	int objThisIDB;//道具B的唯一ID
};

struct item
{
	int id;// 道具ID
	int thisid;//道具唯一ID 
	int aptitude;//资质	
};

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
		sendTextToUser("添加道具成功");
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
	 * @thisid 道具指针
	 * @return 道具是否扣除成功
	 */
	bool removeItem(item* m_item)
	{
		if (m_item == NULL) return false;
		itemMap.erase(m_item->thisid);
		delete m_item;
		m_item = NULL;
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

	
	/**
	 * \brief 从包裹里获取道具指针
	 * @thisid 道具ID
	 * @return 道具指针
	 */
	item* getItemByThisID(const int thisid)
	{
		std::map<int,item*>::iterator it = itemMap.find(thisid);
		if ((it != itemMap.end()) && (it->second != NULL))
			return it->second;
		return NULL;
	}

	bool addItem(item* m_item)
	{
		if (NULL == m_item || itemMap.find(m_item->thisid) != itemMap.end())
			return false;

		itemMap.insert(std::make_pair(m_item->thisid,m_item));
		return true;
	}

	std::map<int,item*> itemMap;
};

/**
 * \brief 玩家类
 */
struct user
{
	package pack;	
};

bool exchangeGem(exchangeGem_CS &cmd,user &m_user)
{
    if(cmd.objThisIDA == cmd.objThisIDB)
    {
        writeLog("ID相同");
        return false;
    }

    item* item1 = m_user.pack.getItemByThisID(cmd.objThisIDA);
    item* item2 = m_user.pack.getItemByThisID(cmd.objThisIDB);

    //Lock needed here
    if(!item1||!item2)
    {
        writeLog("ID对应的物品不存在");
        return false;
    }

    
    if(item1->id != smallDragonID || item2->id != smallDragonID)
    {
        sendTextToUser("请选取两只小火龙");
        return false;
    }

    if(item1->aptitude != 1 || item2->aptitude !=1)
    {
        sendTextToUser("资质不满足");
        return false;
    }

    if(m_user.pack.getSpaceNum() < 2)
    {
        sendTextToUser("包裹空间不足");
        return false;
    }

   if( !m_user.pack.removeItem(item1) || !m_user.pack.removeItem(item2))
   {
       writeLog("移除物品失败");
       return false;
   }

   if( !m_user.pack.addItem(gemID, 100))
   {
       writeLog("增加物品失败");
       return false;
   }
    //UnLock needed here
    return true;
}


int main()
{
	//括号以内代码模拟 客户端消息发送到服务器解包以后，服务器处理逻辑的流程 返回0表示这个消息的处理逻辑结束 
	/* 添加道具
	 * forExample
	 * user m_user;
         * m_user.addItem(1,1);
	 */

	//下面代码可认为是 之前玩家添加相关道具的过程。
	user m_user;
	item *dragon_1 = new item();
	item *dragon_2 = new item();
	if (dragon_1 && dragon_2)
	{
		dragon_1->id = smallDragonID;
		dragon_1->thisid = 1000;
		dragon_1->aptitude = 1;
		dragon_2->id = smallDragonID;
		dragon_2->thisid = 1001;
		dragon_2->aptitude = 1;
	}
	m_user.pack.addItem(dragon_1);
	m_user.pack.addItem(dragon_2);
	//添加流程结束	

	//客户端发起请求流程
	exchangeGem_CS cmd;
	cmd.objThisIDA = 1000;
	cmd.objThisIDB = 1000;
	//服务器处理
	exchangeGem(cmd,m_user);
	return 0;
}

