#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 内部定数
#define D_ON			1										// 汎用フラグ - ON
#define D_OFF			0										// 汎用フラグ - OFF
#define D_VTX_MAX		200000									// 最大頂点数
#define D_EDGE_MAX		D_VTX_MAX								// 最大辺数

// 内部構造体 - 辺情報
typedef struct Edge {
	int miVNo;													// 接続先頂点
	struct Edge *mzpNext;										// 次の辺情報
} Edge;

// 内部構造体 - 頂点情報
typedef struct Vtx {
	char mcDone;												// 処理済フラグ
	int miCnt;													// カウンター
	Edge *mzpEdge;												// 辺
} Vtx;

// 内部変数
static FILE *szpFpI;											// 入力
static Vtx sz1Vtx[D_VTX_MAX];									// 頂点
static int siVCnt;												// 頂点数
static Edge sz1Edge[D_EDGE_MAX * 2];							// 辺
static int siECnt;												// 辺数
static char sc1Out[D_VTX_MAX * 12];								// 出力内容
static char *scpOut;											// 出力位置

// 内部変数 - テスト用
#ifdef D_TEST
	static int siRes;
	static FILE *szpFpA;
	static int siTNo;
#endif

// 出力
int
fOut(
	char *pcpLine				// <I> １行
)
{
	char lc1Buf[1024];

#ifdef D_TEST
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, pcpLine)) {
		siRes = -1;
	}
#else
	printf("%s", pcpLine);
#endif

	return 0;
}

// 出力内容 - 追加
int
fOutAdd(
	int piVal					// <I> 値
)
{
	char lc1Buf[1024];
	sprintf(lc1Buf, "%d ", piVal);
	int liLen = strlen(lc1Buf);
	memcpy(scpOut, lc1Buf, liLen);
	scpOut += liLen;

	return 0;
}

// 辺 - 追加
int
fAddEdge(
	int piVFNo					// <I> 頂点 - 元 0～
	, int piVTNo				// <I> 頂点 - 先 0～
)
{
	sz1Edge[siECnt].miVNo = piVTNo;
	sz1Edge[siECnt].mzpNext = sz1Vtx[piVFNo].mzpEdge;
	sz1Vtx[piVFNo].mzpEdge = &sz1Edge[siECnt];
	siECnt++;

	return 0;
}

// カウンター - 加算
int
fAddCnt(
	int piVNo					// <I> 頂点 0～
	, int piAdd					// <I> 加算値
)
{
	// 処理済フラグ
	if (sz1Vtx[piVNo].mcDone != D_OFF) {
		return 0;
	}
	sz1Vtx[piVNo].mcDone = D_ON;

	// カウンター - 加算
	sz1Vtx[piVNo].miCnt += piAdd;

	// 辺でループ
	Edge *lzpEdge = sz1Vtx[piVNo].mzpEdge;
	while (lzpEdge != NULL) {

		// 下位へ
		fAddCnt(lzpEdge->miVNo, sz1Vtx[piVNo].miCnt);

		// 次の辺へ
		lzpEdge = lzpEdge->mzpNext;
	}

	return 0;
}

// 実行メイン
int
fMain(
)
{
	int i;
	char lc1Buf[1024];

	// 頂点数・操作回数 - 取得
	int liQCnt;
	fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
	sscanf(lc1Buf, "%d%d", &siVCnt, &liQCnt);

	// 辺 - 取得
	for (i = 0; i < siVCnt - 1; i++) {
		int liVNo1, liVNo2;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVNo1, &liVNo2);
		liVNo1--;
		liVNo2--;

		// 辺 - 追加
		fAddEdge(liVNo1, liVNo2);
		fAddEdge(liVNo2, liVNo1);
	}

	// 操作 - 取得
	for (i = 0; i < liQCnt; i++) {
		int liVNo, liCnt;
		fgets(lc1Buf, sizeof(lc1Buf), szpFpI);
		sscanf(lc1Buf, "%d%d", &liVNo, &liCnt);
		liVNo--;

		// カウンター - 加算
		sz1Vtx[liVNo].miCnt += liCnt;
	}

	// カウンター - 加算
	fAddCnt(0, 0);

	// 出力
	for (i = 0; i < siVCnt; i++) {
		fOutAdd(sz1Vtx[i].miCnt);
	}
	*scpOut = '\0';
	scpOut--;
	*scpOut = '\n';
	fOut(sc1Out);

	return 0;
}

// １回実行
int
fOne(
)
{
	int liRet;
	char lc1Buf[1024];

	// データ - 初期化
	memset(sz1Vtx, 0, sizeof(sz1Vtx));							// 頂点
	siECnt = 0;													// 辺数
	scpOut = sc1Out;											// 出力位置

	// 入力 - セット
#ifdef D_TEST
	sprintf(lc1Buf, ".\\Test\\T%d.txt", siTNo);
	szpFpI = fopen(lc1Buf, "r");
	sprintf(lc1Buf, ".\\Test\\A%d.txt", siTNo);
	szpFpA = fopen(lc1Buf, "r");
	siRes = 0;
#else
	szpFpI = stdin;
#endif

	// 実行メイン
	liRet = fMain();

	// 残データ有無
#ifdef D_TEST
	lc1Buf[0] = '\0';
	fgets(lc1Buf, sizeof(lc1Buf), szpFpA);
	if (strcmp(lc1Buf, "")) {
		siRes = -1;
	}
#endif

	// テストファイルクローズ
#ifdef D_TEST
	fclose(szpFpI);
	fclose(szpFpA);
#endif

	// テスト結果
#ifdef D_TEST
	if (siRes == 0) {
		printf("OK %d\n", siTNo);
	}
	else {
		printf("NG %d\n", siTNo);
	}
#endif

	return 0;
}

// プログラム開始
int
main()
{

#ifdef D_TEST
	int i;
	for (i = D_TEST_SNO; i <= D_TEST_ENO; i++) {
		siTNo = i;
		fOne();
	}
#else
	fOne();
#endif

	return 0;
}

