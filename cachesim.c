#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
typedef struct Line_create{
	long int tag; // unique identifier 
	long int address;
	int validBit; // valid bit 
	struct Line_create *next;
	}Line;
typedef struct Set_create{
	// each is a setRow, filled with a blocksize, 
	Line *setLines;  // array of lines / pointer to first node = head
	Line *setLinesTail;
	long int setSize;
	long int set; 
	int numAssoc;
	}Set;
typedef struct Cache_create{
	int cacheHits;
	int cacheMisses;
	int memReads;
	int memWrites;
	int precacheHits;
	int precacheMisses;
	int prememReads;
	int prememWrites;
	int numLines;
	int blockSize;
	int setSize;
	int capacity;
	Set *arraySets; 
	}Cache;
Cache myCache;
Cache pCache;
// simulating both cache with prefetching and without prefetching simultaneously
void createCache(int setSize, int assoc, int E, long int tagged, long int setted){
	int s = 0; 
	int i = 0;
	myCache.setSize = setSize;
	pCache.setSize = setSize;
	myCache.numLines = assoc;
	pCache.numLines = assoc;
	(myCache.arraySets) = (Set *)malloc(sizeof(Set)*setSize);
	(pCache.arraySets) = (Set *)malloc(sizeof(Set)*setSize);
	for ( s = 0; s < setSize; s++){
		myCache.arraySets[s].setLines = (Line*)malloc(sizeof(Line)*assoc);
		pCache.arraySets[s].setLines = (Line*)malloc(sizeof(Line)*assoc);
		myCache.arraySets[s].numAssoc = 0;
		pCache.arraySets[s].numAssoc = 0;
	for ( i = 0; i < assoc; i++){
		myCache.arraySets[s].setLines[i].validBit = 0;
	//myCache.arraySets[s].setLines[i].tag = tagged;
		pCache.arraySets[s].setLines[i].validBit = 0;
	//pCache.arraySets[s].setLines[i].tag = tagged;
	 // each set has a linked list of lines
}
}
}
// making sure the lines in the set all have 1 
bool valid(long int setPlace, int assoc){
	bool ret = true;
	int i = 0;
	for ( i = 0; i < assoc; i++){
	if(myCache.arraySets[setPlace].setLines[i].validBit != 1){
		ret = false;
		break;
	}
	}
		return ret;
}
// same thing for prefetcher
bool prevalid(long int setPlace, int assoc){
bool ret = true;
int i = 0;
	for ( i = 0; i < assoc; i++){
		if(pCache.arraySets[setPlace].setLines[i].validBit != 1){
		ret = false;
		break;
	}
	}
	return ret;
}
void fifo(long int setPlace, long int newTag, long int newAddress, int assoc){
int i = 1;
if(assoc > 1){
	for( i = 1; i < assoc; i++){
		myCache.arraySets[setPlace].setLines[i-1].tag = myCache.arraySets[setPlace].setLines[i].tag;
		pCache.arraySets[setPlace].setLines[i-1].tag = pCache.arraySets[setPlace].setLines[i].tag;
		myCache.arraySets[setPlace].setLines[i-1].address = myCache.arraySets[setPlace].setLines[i].address;
		pCache.arraySets[setPlace].setLines[i-1].address = pCache.arraySets[setPlace].setLines[i].address;
		myCache.arraySets[setPlace].setLines[assoc-1].address = newAddress;
		myCache.arraySets[setPlace].setLines[assoc-1].tag = newTag;
		myCache.arraySets[setPlace].setLines[assoc-1].validBit = 1;
		pCache.arraySets[setPlace].setLines[assoc-1].address = newAddress;
		pCache.arraySets[setPlace].setLines[assoc-1].tag = newTag;
		pCache.arraySets[setPlace].setLines[assoc-1].validBit = 1;
}

}

}
void loadBlock(long int setPlace, long int linePlace, long int tagged, long int addressed){
	myCache.arraySets[setPlace].setLines[linePlace].tag = tagged;
	
	myCache.arraySets[setPlace].setLines[linePlace].address = addressed;
	
	myCache.arraySets[setPlace].setLines[linePlace].validBit = 1;

// time to implement fifo 

}
void loadpreBlock(long int setPlace, long int linePlace, long int tagged, long int prefetched){

	pCache.arraySets[setPlace].setLines[linePlace].tag = tagged;

	pCache.arraySets[setPlace].setLines[linePlace].address = prefetched;

	pCache.arraySets[setPlace].setLines[linePlace].validBit = 1;

}

// check if the lines in the set is empty
 // cache
int nReads = 0;
void cacheRead(long int address, long int tagIt, long int set, char policy,int assoc){
	int reads = 0;
	int areads = 0;
	if(policy == 'R'){
		if(assoc == 1){
//Line* info = (Line *)malloc(sizeof(Line)); // allocate space for the line 
	for(reads = 0; reads < assoc; reads++){ // iterate through number of lines in the set.. we find the set index, match it,    
		if( ((tagIt) == (myCache.arraySets[set].setLines[reads].tag)) && (myCache.arraySets[set].setLines[reads].validBit == 1)){ 
		myCache.cacheHits++;
} 
		else{
// go through the number of lines in each set 
		myCache.cacheMisses++;
		myCache.memReads = myCache.memReads+1;  
		loadBlock(set, reads, tagIt, address);

}
}
}
else{ // associative sets
for (areads = 0; areads< assoc; areads++){
	if((tagIt) == (myCache.arraySets[set].setLines[areads].tag)&& (myCache.arraySets[set].setLines[areads].validBit == 1)){
		myCache.cacheHits++;
	return;
}
}
	myCache.cacheMisses++;
	myCache.memReads++;
	if(valid(set,assoc)){ // if all the lines in that set have a valid bit of 1, we will need to replace. 
		fifo(set, tagIt, address, assoc); // replacement by shifting everything down and putting the last thing on the set the new tag and new address
}
	else{
	if(myCache.arraySets[set].numAssoc < assoc){
		loadBlock(set,(myCache.arraySets[set].numAssoc),tagIt,address);
		if(myCache.arraySets[set].numAssoc+1 < assoc)
		myCache.arraySets[set].numAssoc++;
		} // 0, 1, 2 3, 4, 5, 6, 7  
 // if nReads is the same 
} // add normally.
} // block containing address already loaded in the cache, cache hit, otherwise cache miss. --> note memory read then load into chosen cache line.
}
}
void precacheRead(long int address, long int tagIt, long int set, char policy, int assoc, long int prefetchtag, long int prefetch, long int setprefetch){
// overflow, there are 32 sets. i try to do set+1 which refers to the next one.

	int reads;
	int areads;
	int breads;
	if(policy == 'R'){
	if(assoc == 1){
//Line* info = (Line *)malloc(sizeof(Line)); // allocate space for the line
		for(reads = 0; reads < assoc; reads++){ // iterate through number of lines in the set.. we find the set index, match it,
	if( ((tagIt) == (pCache.arraySets[set].setLines[reads].tag)) && (pCache.arraySets[set].setLines[reads].validBit == 1)){
		pCache.precacheHits++;
}
	else{
// go through the number of lines in each set//
		pCache.precacheMisses++;
		pCache.prememReads++;
		loadpreBlock(set, reads, tagIt, address);
	if(!((prefetchtag == pCache.arraySets[setprefetch].setLines[reads].tag) && (pCache.arraySets[setprefetch].setLines[reads].validBit == 1))){
		pCache.prememReads++; // direct association
		loadpreBlock(setprefetch, reads, prefetchtag, prefetch);
}
}
  // block containing address already loaded in the cache, cache hit, otherwise cache miss. --> note memory read then load into chosen cache line.
}
}


	else{
	for(areads = 0; areads < assoc; areads++){
		if((tagIt) == (pCache.arraySets[set].setLines[areads].tag) && (pCache.arraySets[set].setLines[areads].validBit == 1)){
		pCache.precacheHits++; // A is in cache, so return
		return;
}

}
// if the set does not have a cache hit
	pCache.precacheMisses++;
	pCache.prememReads++;
	if(pCache.arraySets[set].numAssoc < assoc){
	if(valid(set,assoc)){
		fifo(set, tagIt, address, assoc);
	}
	else{
	loadpreBlock(set,(pCache.arraySets[set].numAssoc),tagIt,address);
	pCache.arraySets[set].numAssoc++;}}
	bool prevalid = true; // assume block is there 
	for( breads = 0; breads< assoc; breads++){
		if(!((prefetchtag == pCache.arraySets[setprefetch].setLines[breads].tag) && (pCache.arraySets[setprefetch].setLines[breads].validBit == 1))){
		prevalid = false; // prefetched block is not there  
		}else{
		prevalid = true;
		break;
		}
		}
		if(prevalid == false){
		if((pCache.arraySets[setprefetch].numAssoc)+1 < assoc){
			pCache.prememReads++;
			
		if(valid(set,assoc)){
			fifo(setprefetch, prefetchtag, address, assoc);
		
		}
		
			loadpreBlock(setprefetch, (pCache.arraySets[setprefetch].numAssoc), prefetchtag, prefetch);
			if(pCache.arraySets[setprefetch].numAssoc+1 < assoc)
			pCache.arraySets[setprefetch].numAssoc++;



}
}
}
}
}




void cacheWrite(long int address, long int tagIt, long int set, char policy,int assoc){
long int writes = 0;
int areads = 0;

if(policy == 'W'){
if(assoc == 1){
//Line* info = (Line *)malloc(sizeof(Line)); // pointer to the beginning of the line / memory address 
	for(writes = 0; writes < assoc; writes++){
	if(((tagIt) == (myCache.arraySets[set].setLines[writes].tag)) && (myCache.arraySets[set].setLines[writes].validBit == 1)){ 
		myCache.cacheHits++;
		myCache.memWrites++;
}
	else{
// go through the number of lines in each set 
		myCache.cacheMisses++;
		myCache.memReads++;
		
		loadBlock(set, writes, tagIt, address);
		myCache.memWrites++;
}
}
}

else{
	for(areads = 0; areads< assoc; areads++){
	if((tagIt) == (myCache.arraySets[set].setLines[areads].tag ) && (myCache.arraySets[set].setLines[areads].validBit == 1)){
		myCache.cacheHits++;
		myCache.memWrites++;
		return;
	}
	}
	myCache.cacheMisses++;
	myCache.memReads++;

	if(valid(set,assoc)){
		fifo(set, tagIt, address, assoc);
		
	}
	else{
	if(myCache.arraySets[set].numAssoc < assoc){
		loadBlock(set,(myCache.arraySets[set].numAssoc),tagIt,address);
		myCache.arraySets[set].numAssoc++;
		myCache.memWrites++;
		
}
}
}
}
}
void precacheWrite(long int address, long int tagIt, long int set, char policy, int assoc, long int prefetchtag, long int prefetch, long int setprefetch){
	long int writes = 0;
	int areads = 0;
	int breads = 0;
	if(policy == 'W'){
	if(assoc == 1){
//Line* info = (Line *)malloc(sizeof(Line)); // allocate space for the line
for(writes = 0; writes < assoc; writes++){ // iterate through number of lines in the set.. we find the set index, match it,
	if(((tagIt) == (pCache.arraySets[set].setLines[writes].tag)) && (pCache.arraySets[set].setLines[writes].validBit == 1)){
		pCache.precacheHits++;
		pCache.prememWrites++;
}
	else{
// go through the number of lines in each set//
		pCache.precacheMisses++;
		pCache.prememReads++;	
		loadpreBlock(set,writes,tagIt,address);
		pCache.prememWrites++;
//pCache.prememReads++;
	if(((prefetchtag != (pCache.arraySets[setprefetch].setLines[writes].tag) || (pCache.arraySets[setprefetch].setLines[writes].validBit != 1)))){
		pCache.prememReads++;
		loadpreBlock(setprefetch, writes, prefetchtag, prefetch);
}  // block containing address already loaded in the cache, cache hit, otherwise cache miss. --> note memory read then load into chosen cache line.}}
}
}
}

else{
	
for(areads = 0; areads < assoc; areads++){
	if((tagIt) == (pCache.arraySets[set].setLines[areads].tag) && (pCache.arraySets[set].setLines[areads].validBit == 1)){
		pCache.precacheHits++;
		pCache.prememWrites++;
		return;
}
}
	pCache.precacheMisses++;
	pCache.prememReads++;
	
	if(pCache.arraySets[set].numAssoc < assoc){
	
	if(valid(set,assoc)){
		fifo(set, tagIt, address, assoc);
	}
	else{
		loadpreBlock(set, (pCache.arraySets[set].numAssoc),tagIt,address);
		pCache.prememWrites++;
		pCache.arraySets[set].numAssoc++;}
	}
}
bool prevalid = true;
for( breads = 0; breads < assoc; breads++){

	if(((prefetchtag != pCache.arraySets[setprefetch].setLines[breads].tag) || (pCache.arraySets[setprefetch].setLines[breads].validBit != 1))){
	prevalid = false;
	}
	else{
	prevalid = true;
	break;
	} // prefetched block is not in there, so we should increment memreads
}
	if(prevalid == false){
	if((pCache.arraySets[setprefetch].numAssoc+1) < assoc){
		pCache.prememReads++;
		if(valid(set,assoc)){
			fifo(setprefetch, prefetchtag, address, assoc);
	}
		
		loadpreBlock(setprefetch, (pCache.arraySets[setprefetch].numAssoc), prefetchtag, prefetch);
		pCache.arraySets[setprefetch].numAssoc++;
		

}
}
}
}
int logTwo(int num){ // log deals with positive numbers
// create log number
int log = 0;
	while(num>>=1){ // repeatedly divides by 2, so if num is 16, 16 >> 1 becomes 8 log++ 8 >> 1 becomes 4 log++ 4 >> 1 becomes 2 log++ 2 >> 1 = 1 log++; return 4.
		log++;
}
return log;
}
bool isPowerOf2(int num){
// checking if power of two
	int i = 0;	
	int two = 2;
	for ( i = 0; i <= num; i++){
		if( pow(two, i) == num )
	return true;

	}
	return false;
}

void printnoPrefetch(){
	printf("%s\n", "no-prefetch");
	printf("Cache hits: %d\n", myCache.cacheHits);
	printf("Cache misses: %d\n", myCache.cacheMisses);
	printf("Memory reads: %d\n", myCache.memReads);
	printf("Memory writes: %d\n", myCache.memWrites);
}
void printwithPrefetch(){
	printf("%s\n", "with-prefetch");
	printf("Cache hits: %d\n", pCache.precacheHits);
	printf("Cache misses: %d\n", pCache.precacheMisses);
	printf("Memory reads: %d\n", pCache.prememReads);
	printf("Memory writes: %d\n", pCache.prememWrites);
}
int main(int argc, char *argv[]){
	int cacheSize = 0;
	char line[100];
	int setIndex = 0; // log2S = s <=== set index;
	int blockOffset = 0; // log2B = b <=== block offset
	if (isPowerOf2(atoi(argv[1])) == true)
	cacheSize = atoi(argv[1]);
	else 
	exit(0); // cache size is not a power of 2
// replacement policy, fifo / lru, fifo cache line loaded least recently will be replaced

	if(strncmp(argv[3], "fifo", 4) == 0){

	}

	else if(strncmp(argv[3], "lru", 3) == 0){
	exit(0);
}
	int blockSize = 0;
	if(isPowerOf2(atoi(argv[4])) == true){
	blockSize = atoi(argv[4]);
	blockOffset = logTwo(blockSize);
	}
	else
	exit(0);
	
	int setSize = 0; 
	int assoc = 0;
// associativity = number of cache lines per set
	if((strncmp(argv[2], "direct", 6)) == 0){
	// find set index // C = SAB c and b are known and A is 1 
	setSize = (cacheSize / blockSize);
	setIndex = logTwo(setSize);
	assoc = 1;
	}
	else if (strncmp(argv[2], "assoc", 6) == 0){ // need to change something to compare string with 
	setSize = 1;
	setIndex = logTwo(setSize);
	assoc = (cacheSize / blockSize);
	}
	else{
	if(isPowerOf2(atoi(&argv[2][6])) == true){
	assoc = atoi(&argv[2][6]);
	
	setSize = cacheSize / (blockSize * assoc);
	setIndex = logTwo(setSize);
	}
	}
	
	FILE *fp = fopen(argv[5], "r");
	if( fp == 0){
	printf("%s", "error");
	return -1;
	}
// local variables


//int blockMask = 0;
//int tagBits = 48 - blockOffset - setIndex;
	long int tagMask = 0;
	long int setMask = 0;
	long int csetMask = 0;
	long int prefetch = 0;
	long int setprefetch = 0;
	long int setprefetchmask = 0;
	long int prefetchtag = 0;
	int capacity = (setSize * assoc * blockSize);
	long int address = 0; // hexadecimal value
	char mode = '\0'; // R or W
	char pc[30]; // program counter
	createCache(setSize, assoc,capacity, tagMask, setMask);
while(fgets(line, 100, fp)){
	sscanf(line, "%s %c %lx", pc, &mode, &address);
	if(strcmp(pc, "#eof") == 0)
	break;
	else{ // blockOffset, setIndex
		tagMask = address>>(blockOffset + setIndex);
		csetMask = (address>>blockOffset);
		setMask = (csetMask & ((1 << setIndex)-1));
		prefetch = (address + blockSize);
		setprefetchmask = (prefetch >> blockOffset);
		setprefetch = (setprefetchmask & ((1<<setIndex)-1)); // new address... might need to get new blockoffset and set index c = sab capacity = lines blocks and 
		prefetchtag = prefetch >> (blockOffset + setIndex);
		precacheRead(address, tagMask, setMask, mode, assoc, prefetchtag, prefetch, setprefetch);
		cacheRead(address, tagMask, setMask, mode, assoc);
		cacheWrite(address,tagMask, setMask, mode,assoc);
		precacheWrite(address, tagMask, setMask, mode, assoc, prefetchtag, prefetch,setprefetch);

}
	mode = '\0';
	pc[0] = 0;
}
	printnoPrefetch();
	printwithPrefetch();
	feof(fp);
	return 0;	
}
