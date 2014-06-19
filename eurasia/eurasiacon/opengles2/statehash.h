/**************************************************************************
 * Name         : statehash.h
 *
 * Copyright    : 2006-2008 by Imagination Technologies Limited.
 *              : All rights reserved. No part of this software, either
 *              : material or conceptual may be copied or distributed,
 *              : transmitted, transcribed, stored in a retrieval system or
 *              : translated into any human or computer language in any form
 *              : by any means, electronic, mechanical, manual or other-wise,
 *              : or disclosed to third parties without the express written
 *              : permission of Imagination Technologies Limited, Home Park
 *              : Estate, Kings Langley, Hertfordshire, WD4 8LZ, U.K.
 *
 * Platform     : ANSI
 *
 * $Log: statehash.h $
 **************************************************************************/

#ifndef _STATEHASH_H_
#define _STATEHASH_H_

#define STATEHASH_INIT_VALUE 		0x9e3779b9
#define STATEHASH_LOG2TABLESIZE 	10
#define STATEHASH_MAXNUMENTRIES 	8192

typedef IMG_UINT32 HashValue;

typedef struct HashEntry_TAG
{
	HashValue	tHashValue;				/* Hash value, as generated by hash function */

	IMG_UINT32 *pui32HashKey;			/* Data used to generate hash value */
	IMG_UINT32  ui32HashKeySizeInDWords;/* Size of hash key in DWords */

	IMG_UINT32	ui32Item;				/* Data item */

	IMG_UINT32	ui32LastFrameHashed;	/* The last frame this item was searched found by
										   HashTableSearch(). Initialised to the current frame
										   by HashTableInsert() */

	struct HashEntry_TAG *psNext;		/* Pointer to next item in hash-chain, to resolve hash conflicts */

} HashEntry;

typedef IMG_VOID (* PFNDestroyHashItem)(GLES2Context *gc, IMG_UINT32 ui32Item);

typedef struct HashTable_TAG
{
	IMG_UINT32	ui32NumEntries;			/* How many entries have been placed into table */
	IMG_UINT32	ui32NumHashValues;		/* How many hash values have been used */
	IMG_UINT32	ui32PeakNumEntries;		/* Peak number of entries in the table */
	IMG_UINT32	ui32PeakNumHashValues;	/* Peak number of hash values that have been used */

	IMG_UINT32	ui32TableSize;				/* Size of hash table (how many possible hash-values) */
	IMG_UINT32	ui32HashValueMask;			/* Bit-mask to apply to hash-value to get entry into table */
	IMG_UINT32	ui32MaxNumEntries;			/* Limit on the number of entries that can be inserted into
										   	   the hash table. Once this limit is reached, one entry will
										   	   be removed for each new entry that is added. */

	PFNDestroyHashItem pfnDestroyItemFunc; /* Function to call when deleting entries from
											  the hash table */

	HashEntry	**psTable;

} HashTable;

/* ui32Log2TableSize is log2(desired table size) */
IMG_BOOL HashTableCreate(GLES2Context		*gc,
						 HashTable			*psHashTable,
						 IMG_UINT32			ui32Log2TableSize,
						 IMG_UINT32			ui32MaxNumEntries,
						 PFNDestroyHashItem	pfnDestroyItemFunc);

IMG_VOID HashTableDestroy(GLES2Context *gc,
						  HashTable	   *psHashTable);

HashValue HashFunc(IMG_UINT32 *pui32HashKey,
				   IMG_UINT32 ui32KeySizeInDwords, 
				   IMG_UINT32 ui32InitialValue);

IMG_BOOL HashTableSearch(GLES2Context *gc,
						HashTable	  *psHashTable,
						HashValue	  tHashValue, 
						IMG_UINT32	  *pui32HashKey,
						IMG_UINT32	  ui32HashKeySizeInDWords,	
						IMG_UINT32    *pui32Item);

IMG_VOID HashTableInsert(GLES2Context *gc,
						HashTable	  *psHashTable,
						HashValue	  tHashValue,
						IMG_UINT32	  *pui32HashKey,
						IMG_UINT32	  ui32HashKeySizeInDWords,
						IMG_UINT32	  ui32Item);

IMG_BOOL HashTableDelete(GLES2Context *gc,
						HashTable	  *psHashTable,
						HashValue	  tHashValue,
						IMG_UINT32	  *pui32HashKey,
						IMG_UINT32	  ui32HashKeySizeInDWords,
						IMG_UINT32	  *pui32Item);
#endif
