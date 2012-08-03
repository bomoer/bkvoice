//---------------------------------------------------------------------------

#ifndef MainFrmH
#define MainFrmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "config.h"

typedef struct tagAudioBuf AUDIOBUF, *pAUDIOBUF;

//��Ƶ�ɼ����Žṹ
struct tagAudioBuf
{
	//char valid;
	char recordvalid;//¼����Ч
	pAUDIOBUF pNext;
	int count;//��Ч��������
	//short data[SIZE_AUDIO_FRAME/2];
        signed char *data;
#if SPEEX_ENABLED	
	char speexencodevalid;//speex�����������Ƿ���Ч
	char speexdecodevalid;//speex�����������Ƿ���Ч
	char speexdata[SIZE_AUDIO_FRAME];//speex���������
	short datadecode[SIZE_AUDIO_FRAME];//speex���������
#endif
};



//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *edtToAddr;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
        //void init_audio_buffer();
        HANDLE hRecord, hPlay, hUDPSend;
	HANDLE eventRecord, eventPlay, eventUDPSend;
	DWORD threadRecord, threadPlay, threadUDPSend;

        static DWORD WINAPI voice_record_thread_runner(LPVOID lpParam);
        static DWORD WINAPI voice_udpsend_thread_runner(LPVOID lpParam);
        void init_audio_buffer();//��ʼ����Ƶ������
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
