#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <map>
#include <any>
#include "indexinfo.h"
#include "CatalogManager.h"
#include "Def.h"
/// <summary>
/// ����ֵΪvector�ĺ��������û��ʲô���Է��صģ��ͷ���һ��sizeΪ0��vector
/// ����ֵΪstring�ĺ��������û��ʲô���Է��صģ��ͷ��ؿ��ַ���""��
/// </summary>
class IndexManager {
private:
	
	std::map<int, IndexInfo*> indexmap;
	std::shared_ptr<CatalogManager> catalogManager;
	int getdegree(catalog type);
	int getkeysize(catalog type);


	void writeintoBuffer();

	void readfromBuffer();

	void* getindex(std::string tableName, std::string indexName);
		
public:


	int test();

	/// <summary>
	/// �������ݿ�ʱ���ã�������index�����ļ�
	/// </summary>
	IndexManager(std::shared_ptr<CatalogManager> _catalogManager);
	/// <summary>
	///	�ر����ݿ�ʱ����ã�������indexд���ļ�
	/// </summary>
	void close();

	/// <summary>
	/// Ϊָ�����ָ�����Դ���һ����ΪindexName����������������Ѿ�����������Ϊ�ۼ���������û�У���Ϊ����������
	/// </summary>
	/// <param name="indexName">Name of the index.</param>
	/// <param name="tableName">Name of the table.</param>
	/// <param name="attrName">Name of the attribute.</param>
    void* createIndex(std::string indexName, std::string tableName, std::string attrName);
	/// <summary>
	/// ɾ����ָ����Ľ���ָ��������������
	/// </summary>
	/// <param name="indexName">Name of the index.</param>
	/// <param name="tableName">Name of the table.</param>
	void dropIndex(std::string indexName, std::string tableName);
	/// <summary>
	/// ɾ����ָ�������������
	/// </summary>
	/// <param name="tableName">Name of the table.</param>
	void dropAllIndex(std::string tableName);

	void insertToIndex(std::string indexName, std::string tableName, std::any key, int64 value);
	
	std::vector<int64> selectIndexsByCondition(std::string tableName, std::string indexName, std::vector<condition> cond);

	void removeIndexByAddress(std::string tableName, std::vector<int64> addresses);
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
