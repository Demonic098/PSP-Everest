#include <pspsdk.h>
#include <pspkernel.h>

PSP_MODULE_INFO("pspUmdMan_Driver", 0x1000, 1, 0);
PSP_MAIN_THREAD_ATTR(0);

int sceUmdManGetUmdDrive(int driveNum);
int sceUmdExecInquiryCmd(void *drive, u8 *param, u8 *buf);

void *_sceUmdManGetUmdDrive(int driveNum)
{
	int k1 = pspSdkSetK1(0);
	void *drive = (void *)sceUmdManGetUmdDrive(driveNum);

	pspSdkSetK1(k1);

	return drive;
}

int _sceUmdExecInquiryCmd(void *drive, u8 *param, u8 *buf)
{
	int k1 = pspSdkSetK1(0);
	int res = sceUmdExecInquiryCmd(drive, param, buf);

	pspSdkSetK1(k1);

	return(res);
}

int module_start(SceSize args, void *argp)
{
	return 0;
}

int module_stop()
{
	return 0;
}
