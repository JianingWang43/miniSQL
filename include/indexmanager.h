#pragma once
#include <string>
#include <vector>
#include <map>
#include "bplustree.h"
#include "indexinfo.h"
using namespace std;
/// <summary>
/// ����ֵΪvector�ĺ��������û��ʲô���Է��صģ��ͷ���һ��sizeΪ0��vector
/// ����ֵΪstring�ĺ��������û��ʲô���Է��صģ��ͷ��ؿ��ַ���""��
/// </summary>
class IndexManager {
public:
	
	int static const FLOAT = 0;
	int static const INT = -1;
	
	struct keytmp {
		int inttmp;
		float floattmp;
		string stringtmp;
	}tmp;
	
	map<int, IndexInfo*> indexmap;
	
	int getdegree(int type);
	int getkeysize(int type);
		
public:


	int test();

	/// <summary>
	/// �������ݿ�ʱ���ã�������index�����ļ�
	/// </summary>
	IndexManager(std::string tableName);
	/// <summary>
	///	�ر����ݿ�ʱ����ã�������indexд���ļ�
	/// </summary>
	void close();
	
	int writeintoBuffer();
	
	void setkey(int type, string key);
	
	int getkeysize(int type);
	
	void* getindex(string indexName);

	/// <summary>
	/// Ϊָ�����ָ�����Դ���һ����ΪindexName����������������Ѿ�����������Ϊ�ۼ���������û�У���Ϊ����������
	/// </summary>
	/// <param name="indexName">Name of the index.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="attrName">Name of the attribute.</param>
    void* createIndex(std::string indexName, std::string tableName, std::string attrName, int type);
	/// <summary>
	/// ɾ����ָ����Ľ���ָ��������������
	/// </summary>
	/// <param name="indexName">Name of the index.</param>
	/// <param name="tableName">Name of the table.</param>
	void dropIndex(std::string indexName);
	/// <summary>
	/// ɾ����ָ�������������
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	void dropAllIndex();

	void insertToIndex(std::string indexName,std::string key, int64 fileAddresses, int type);
	
	std::vector<int64> selectIndexsByCondition(std::string TableName, std::string indexName, std::vector<condition> cond);

	void removeIndexByCondition(std::string TableName, std::string indexName, condition cond);
	void removeIndexByCondition(std::string TableName, std::string indexName, std::vector<condition> cond);
	/// <summary>
	/// Determines whether [has clustered index] [the specified table name].
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns>
	///   <c>true</c> if [has clustered index] [the specified table name]; otherwise, <c>false</c>.
	/// </returns>
	bool hasClusteredIndex(std::string tableName);

	/// <summary>
	/// Gets the index of the clustered.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns>name of index</returns>
	std::string getClusteredIndex(std::string tableName);

	/// <summary>
	/// Determines whether [has non clustered index] [the specified table name].
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns>
	///   <c>true</c> if [has non clustered index] [the specified table name]; otherwise, <c>false</c>.
	/// </returns>
	bool hasNonClusteredIndex(std::string tableName);

	/// <summary>
	/// Gets the index of the non clustered.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns>names of indexes</returns>
	std::vector<std::string> getNonClusteredIndex(std::string tableName);
	/// <summary>
	/// Determines whether [has any index] [the specified table name].
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns>
	///   <c>true</c> if [has any index] [the specified table name]; otherwise, <c>false</c>.
	/// </returns>
	bool hasAnyIndex(std::string tableName);
	/// <summary>
	/// Gets all index.
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	/// <returns></returns>
	std::vector<std::string> getAllIndex(std::string tableName);
	
	/// <summary>
	/// Gets the name of the attribute name by index name and table name.
	/// </summary>
	/// <param name="indexName">Name of the index.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <returns></returns>
	std::string getAttrNameByIndexName(std::string indexName, std::string tableName);
	/// <summary>
	/// Gets the name of the index name by attribute.
	/// </summary>
	/// <param name="attrName">Name of the attribute.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <returns></returns>
	std::string getIndexNameByAttrName(std::string attrName, std::string tableName);

	//std::string getBestIndex(std::string tableName);
};
