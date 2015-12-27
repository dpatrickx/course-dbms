#ifndef BPLUS_NODE
#define BPLUS_NODE

#define NULL 0

enum NODE_TYPE{INTERNAL, LEAF};        // 结点类型：内结点、叶子结点
enum SIBLING_DIRECTION{LEFT, RIGHT};   // 兄弟结点方向：左兄弟结点、右兄弟结点
typedef float KeyType;                 // 键类型
typedef int DataType;                  // 值类型
const int ORDER = 7;                   // B+树的阶（非根内结点的最小子树个数）
const int MINNUM_KEY = ORDER-1;        // 最小键值个数
const int MAXNUM_KEY = 2*ORDER-1;      // 最大键值个数
const int MINNUM_CHILD = MINNUM_KEY+1; // 最小子树个数
const int MAXNUM_CHILD = MAXNUM_KEY+1; // 最大子树个数
const int MINNUM_LEAF = MINNUM_KEY;    // 最小叶子结点键值个数
const int MAXNUM_LEAF = MAXNUM_KEY;    // 最大叶子结点键值个数

// 结点基类
class CNode{
public:
	CNode();
	virtual ~CNode();

	NODE_TYPE getType() const {return m_Type;}
	void setType(NODE_TYPE type){m_Type = type;}
	int getKeyNum() const {return m_KeyNum;}
	void setKeyNum(int n){m_KeyNum = n;}
	KeyType getKeyValue(int i) const {return m_KeyValues[i];}
	void setKeyValue(int i, KeyType key){m_KeyValues[i] = key;}
	int getKeyIndex(KeyType key)const;  // 找到键值在结点中存储的下标
	// 纯虚函数，定义接口
	virtual void removeKey(int keyIndex, int childIndex)=0;  // 从结点中移除键值
	virtual void split(CNode* parentNode, int childIndex)=0; // 分裂结点
	virtual void mergeChild(CNode* parentNode, CNode* childNode, int keyIndex)=0;  // 合并结点
	virtual void clear()=0; // 清空结点，同时会清空结点所包含的子树结点
	virtual void borrowFrom(CNode* destNode, CNode* parentNode, int keyIndex, SIBLING_DIRECTION d)=0; // 从兄弟结点中借一个键值
	virtual int getChildIndex(KeyType key, int keyIndex)const=0;  // 根据键值获取孩子结点指针下标
protected:
	NODE_TYPE m_Type;
	int m_KeyNum;
	KeyType m_KeyValues[MAXNUM_KEY];
};

// 内结点
class CInternalNode : public CNode{
public:
	CInternalNode();
	virtual ~CInternalNode();

	CNode* getChild(int i) const {return m_Childs[i];}
	void setChild(int i, CNode* child){m_Childs[i] = child;}
	void insert(int keyIndex, int childIndex, KeyType key, CNode* childNode);
	virtual void split(CNode* parentNode, int childIndex);
	virtual void mergeChild(CNode* parentNode, CNode* childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(CNode* destNode, CNode* parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(KeyType key, int keyIndex)const;
private:
	CNode* m_Childs[MAXNUM_CHILD];
};

// 叶子结点
class CLeafNode : public CNode{
public:
	CLeafNode();
	virtual ~CLeafNode();

	CLeafNode* getLeftSibling() const {return m_LeftSibling;}
	void setLeftSibling(CLeafNode* node){m_LeftSibling = node;}
	CLeafNode* getRightSibling() const {return m_RightSibling;}
	void setRightSibling(CLeafNode* node){m_RightSibling = node;}
	DataType getData(int i) const {return m_Datas[i];}
	void setData(int i, const DataType& data){m_Datas[i] = data;}
	void insert(KeyType key, const DataType& data);
	virtual void split(CNode* parentNode, int childIndex);
	virtual void mergeChild(CNode* parentNode, CNode* childNode, int keyIndex);
	virtual void removeKey(int keyIndex, int childIndex);
	virtual void clear();
	virtual void borrowFrom(CNode* destNode, CNode* parentNode, int keyIndex, SIBLING_DIRECTION d);
	virtual int getChildIndex(KeyType key, int keyIndex)const;
private:
	CLeafNode* m_LeftSibling;
	CLeafNode* m_RightSibling;
	DataType m_Datas[MAXNUM_LEAF];
};

// CNode  
CNode::CNode(){  
    setType(LEAF);  
    setKeyNum(0);  
}  
  
CNode::~CNode(){  
    setKeyNum(0);  
}  
  
int CNode::getKeyIndex(KeyType key)const  
{  
    int left = 0;  
    int right = getKeyNum()-1;  
    int current;  
    while(left!=right)  
    {  
        current = (left+right)/2;  
        KeyType currentKey = getKeyValue(current);  
        if (key>currentKey)  
        {  
            left = current+1;  
        }  
        else  
        {  
            right = current;  
        }  
    }  
    return left;  
}  
  
// CInternalNode  
CInternalNode::CInternalNode():CNode(){  
    setType(INTERNAL);  
}  
  
CInternalNode::~CInternalNode(){  
      
}  
  
void CInternalNode::clear()  
{  
    for (int i=0; i<=m_KeyNum; ++i)  
    {  
        m_Childs[i]->clear();  
        delete m_Childs[i];  
        m_Childs[i] = NULL;  
    }  
}  
  
void CInternalNode::split(CNode* parentNode, int childIndex)  
{  
    CInternalNode* newNode = new CInternalNode();//分裂后的右节点  
    newNode->setKeyNum(MINNUM_KEY);  
    int i;  
    for (i=0; i<MINNUM_KEY; ++i)// 拷贝关键字的值  
    {  
        newNode->setKeyValue(i, m_KeyValues[i+MINNUM_CHILD]);  
    }  
    for (i=0; i<MINNUM_CHILD; ++i) // 拷贝孩子节点指针  
    {  
        newNode->setChild(i, m_Childs[i+MINNUM_CHILD]);  
    }  
    setKeyNum(MINNUM_KEY);  //更新左子树的关键字个数  
    ((CInternalNode*)parentNode)->insert(childIndex, childIndex+1, m_KeyValues[MINNUM_KEY], newNode);  
}  
  
void CInternalNode::insert(int keyIndex, int childIndex, KeyType key, CNode* childNode){  
    int i;  
    for (i=getKeyNum(); i>keyIndex; --i)//将父节点中的childIndex后的所有关键字的值和子树指针向后移一位  
    {  
        setChild(i+1,m_Childs[i]);  
        setKeyValue(i,m_KeyValues[i-1]);  
    }  
    if (i==childIndex)  
    {  
        setChild(i+1, m_Childs[i]);  
    }  
    setChild(childIndex, childNode);  
    setKeyValue(keyIndex, key);  
    setKeyNum(m_KeyNum+1);  
}  
  
void CInternalNode::mergeChild(CNode* parentNode, CNode* childNode, int keyIndex)  
{  
    // 合并数据  
    insert(MINNUM_KEY, MINNUM_KEY+1, parentNode->getKeyValue(keyIndex), ((CInternalNode*)childNode)->getChild(0));  
    int i;  
    for (i=1; i<=childNode->getKeyNum(); ++i)  
    {  
        insert(MINNUM_KEY+i, MINNUM_KEY+i+1, childNode->getKeyValue(i-1), ((CInternalNode*)childNode)->getChild(i));  
    }  
    //父节点删除index的key  
    parentNode->removeKey(keyIndex, keyIndex+1);  
    delete ((CInternalNode*)parentNode)->getChild(keyIndex+1);  
}  
  
void CInternalNode::removeKey(int keyIndex, int childIndex)  
{  
    for (int i=0; i<getKeyNum()-keyIndex-1; ++i)  
    {  
        setKeyValue(keyIndex+i, getKeyValue(keyIndex+i+1));  
        setChild(childIndex+i, getChild(childIndex+i+1));  
    }  
    setKeyNum(getKeyNum()-1);  
}  
  
void CInternalNode::borrowFrom(CNode* siblingNode, CNode* parentNode, int keyIndex, SIBLING_DIRECTION d)  
{  
    switch(d)  
    {  
    case LEFT:  // 从左兄弟结点借  
        {  
            insert(0, 0, parentNode->getKeyValue(keyIndex), ((CInternalNode*)siblingNode)->getChild(siblingNode->getKeyNum()));  
            parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(siblingNode->getKeyNum()-1));  
            siblingNode->removeKey(siblingNode->getKeyNum()-1, siblingNode->getKeyNum());  
        }  
        break;  
    case RIGHT:  // 从右兄弟结点借  
        {  
            insert(getKeyNum(), getKeyNum()+1, parentNode->getKeyValue(keyIndex), ((CInternalNode*)siblingNode)->getChild(0));  
            parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));  
            siblingNode->removeKey(0, 0);  
        }  
        break;  
    default:  
        break;  
    }  
}  
  
int CInternalNode::getChildIndex(KeyType key, int keyIndex)const  
{  
    if (key==getKeyValue(keyIndex))  
    {  
        return keyIndex+1;  
    }  
    else  
    {  
        return keyIndex;  
    }  
}  
  
// CLeafNode  
CLeafNode::CLeafNode():CNode(){  
    setType(LEAF);  
    setLeftSibling(NULL);  
    setRightSibling(NULL);  
}  
  
CLeafNode::~CLeafNode(){  
  
}  
  
void CLeafNode::clear()  
{  
    for (int i=0; i<m_KeyNum; ++i)  
    {  
        // if type of m_Datas is pointer  
        //delete m_Datas[i];  
        //m_Datas[i] = NULL;  
    }  
}  
  
void CLeafNode::insert(KeyType key, const DataType& data)  
{  
    int i;  
    for (i=m_KeyNum; i>=1 && m_KeyValues[i-1]>key; --i)  
    {  
        setKeyValue(i, m_KeyValues[i-1]);  
        setData(i, m_Datas[i-1]);  
    }  
    setKeyValue(i, key);  
    setData(i, data);  
    setKeyNum(m_KeyNum+1);  
}  
  
void CLeafNode::split(CNode* parentNode, int childIndex)  
{  
    CLeafNode* newNode = new CLeafNode();//分裂后的右节点  
    setKeyNum(MINNUM_LEAF);    
    newNode->setKeyNum(MINNUM_LEAF+1);  
    newNode->setRightSibling(getRightSibling());  
    setRightSibling(newNode);  
    newNode->setLeftSibling(this);  
    int i;  
    for (i=0; i<MINNUM_LEAF+1; ++i)// 拷贝关键字的值  
    {  
        newNode->setKeyValue(i, m_KeyValues[i+MINNUM_LEAF]);  
    }  
    for (i=0; i<MINNUM_LEAF+1; ++i)// 拷贝数据  
    {  
        newNode->setData(i, m_Datas[i+MINNUM_LEAF]);  
    }  
    ((CInternalNode*)parentNode)->insert(childIndex, childIndex+1, m_KeyValues[MINNUM_LEAF], newNode);  
}  
  
void CLeafNode::mergeChild(CNode* parentNode, CNode* childNode, int keyIndex)  
{  
    // 合并数据  
    for (int i=0; i<childNode->getKeyNum(); ++i)  
    {  
        insert(childNode->getKeyValue(i), ((CLeafNode*)childNode)->getData(i));  
    }  
    setRightSibling(((CLeafNode*)childNode)->getRightSibling());  
    //父节点删除index的key，  
    parentNode->removeKey(keyIndex, keyIndex+1);  
}  
  
void CLeafNode::removeKey(int keyIndex, int childIndex)  
{  
    for (int i=keyIndex; i<getKeyNum()-1; ++i)  
    {  
        setKeyValue(i, getKeyValue(i+1));  
        setData(i, getData(i+1));  
    }  
    setKeyNum(getKeyNum()-1);  
}  
  
void CLeafNode::borrowFrom(CNode* siblingNode, CNode* parentNode, int keyIndex, SIBLING_DIRECTION d)  
{  
    switch(d)  
    {  
    case LEFT:  // 从左兄弟结点借  
        {  
            insert(siblingNode->getKeyValue(siblingNode->getKeyNum()-1), ((CLeafNode*)siblingNode)->getData(siblingNode->getKeyNum()-1));  
            siblingNode->removeKey(siblingNode->getKeyNum()-1, siblingNode->getKeyNum()-1);  
            parentNode->setKeyValue(keyIndex, getKeyValue(0));             
        }  
        break;  
    case RIGHT:  // 从右兄弟结点借  
        {  
            insert(siblingNode->getKeyValue(0), ((CLeafNode*)siblingNode)->getData(0));  
            siblingNode->removeKey(0, 0);  
            parentNode->setKeyValue(keyIndex, siblingNode->getKeyValue(0));  
        }  
        break;  
    default:  
        break;  
    }  
}  
  
int CLeafNode::getChildIndex(KeyType key, int keyIndex)const  
{  
    return keyIndex;  
}  

#endif