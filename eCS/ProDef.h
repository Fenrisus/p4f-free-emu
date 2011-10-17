#ifndef __PROTOCOLDEF__
#define __PROTOCOLDEF__
//////////////////////////////////////////////////////////////////////////////
// �������ݿ� ���

#define PMHC_BYTE				0xC1 // Ŭ���̾�Ʈ�� ������ 1����Ʈ¥�� �������� 
#define PMHC_WORD				0xC2 // Ŭ���̾�Ʈ�� ������ 2����Ʈ¥�� �������� 
#define PMHCE_BYTE				0xC3 // Ŭ���̾�Ʈ�� ������ 1����Ʈ¥�� �������� 
#define PMHCE_WORD				0xC4 // Ŭ���̾�Ʈ�� ������ 2����Ʈ¥�� �������� 

typedef struct
{
	BYTE c;			// �������� �ڵ�
	BYTE size;		// �������� ũ��( ��� ũ�� ���� )
	BYTE headcode;	// �������� ����
} PBMSG_HEAD, *LPPBMSG_HEAD;

typedef struct
{
	BYTE c;			// �������� �ڵ�
	BYTE sizeH;		// �������� ũ��( ��� ũ�� ���� ) ����
	BYTE sizeL;
	BYTE headcode;	// �������� ����
} PWMSG_HEAD, *LPPWMSG_HEAD;


typedef struct
{
	BYTE c;			// �������� �ڵ�
	BYTE size;		// �������� ũ��( ��� ũ�� ���� )
	BYTE headcode;	// �������� ����
	BYTE subcode;	// ���� �������� ����
} PBMSG_HEAD2, * LPPBMSG_HEAD2;

typedef struct
{
	BYTE c;			// �������� �ڵ�
	BYTE sizeH;		// �������� ũ�� ���� ����Ʈ
	BYTE sizeL;		// �������� ũ�� ���� ����Ʈ
	BYTE headcode;	// �������� ����
	BYTE subcode;	// ���� �������� ����
} PWMSG_HEAD2, * LPPWMSG_HEAD2;


//----------------------------------------------------------------------------
// ī����
//----------------------------------------------------------------------------
typedef struct
{
	PBMSG_HEAD	h;
	BYTE		count;
} PBMSG_COUNT, * LPPBMSG_COUNT;


//----------------------------------------------------------------------------
// ī����
//----------------------------------------------------------------------------
typedef struct
{
	PWMSG_HEAD	h;
	BYTE		count;
} PWMSG_COUNT, * LPPWMSG_COUNT;

//----------------------------------------------------------------------------
// SUBCODE �� �ִ� ī���� 
//----------------------------------------------------------------------------
typedef struct
{
	PBMSG_HEAD	h;
	BYTE		subcode;
	BYTE		count;
} PBMSGS_COUNT, * LPPBMSGS_COUNT;


#endif
