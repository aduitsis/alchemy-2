#ifndef CACHE__
#define CACHE__
#include "lvrmln.h"
#include "unifier.h"

struct LCacheEntry
{
	vector<WClause*> CNF;
	LogDouble wCount;
	LCacheEntry(vector<WClause*> CNF_,LogDouble wCount_);
	bool deleteFlag;
  	int hits;
	~LCacheEntry();
};

struct LCache
{
	bool addToCache(vector<WClause*> CNF, LogDouble wCount);
	bool findInCache(vector<WClause*> CNF, LogDouble& val);
	void cleanCache(int numItemsToRemove);
	void printCache();
	LCache(LvrMLN& mln_,int cacheSize_ = CACHESIZE);
	~LCache();
private:
	vector<vector<LCacheEntry*> > cacheIndex;
	vector<LCacheEntry*> cacheEntries;
	vector<int> mostRecentList;
	LvrMLN& mln;
	int cacheSize;
	int currentIndex;
	int successfulHits;
	int misses;
	int hits;
	int markStart;
	int markEnd;
	int numEntries;
  	int mostRecentCounter;
	LUnifier* unifier;
	bool isFull()
	{
          return (unsigned) numEntries == cacheEntries.size();
	}
};


#endif
