#include <iostream>
#include <libusb.h>
#include <stdio.h>
using namespace std;

void null_str(unsigned char* str)
{
	str[0] = 'e';
	str[1] = 'r';
	str[2] = 'r';
	str[3] = 'o';
	str[4] = 'r';
	for (int i = 5; i < 64; i++)
	{
		str[i] = 0;
	}
}

void printdev(libusb_device* dev)
{
	libusb_device_descriptor desc; // ���������� ����������
	libusb_config_descriptor* config; // ���������� ������������ �������
	const libusb_interface* inter;
	const libusb_interface_descriptor* interdesc;
	const libusb_endpoint_descriptor* epdesc;
	int r = libusb_get_device_descriptor(dev, &desc);
	if (r < 0)
	{
		fprintf(stderr, "Error: device descriptor didn't received, code: %d.\n", r);
		return;
	}
	libusb_get_config_descriptor(dev, 0, &config); // �������� ������������ ����������
	printf("  Number of possible configurations: %d\n", (int)desc.bNumConfigurations); // ���������� ��������� ������������
	printf("  Device Class: %d (%x)\n", (int)desc.bDeviceClass, (int)desc.bDeviceClass); // ����� ����������
	printf("  VendorID: %d (%x)\n", desc.idVendor, desc.idVendor); // ������������� �������������
	printf("  ProductID: %d (%x)\n", desc.idProduct, desc.idProduct); // ������������� ����������
	printf("  Interfaces: %d\n", (int)config->bNumInterfaces); // ���������� �����������
	libusb_device_handle* handle = NULL;
	unsigned char striSerialNumber[64];
	unsigned char striManufacturer[64];
	unsigned char striProduct[64];
	null_str(striSerialNumber);
	null_str(striManufacturer);
	null_str(striProduct);
	r = libusb_open(dev, &handle);
	r = libusb_claim_interface(handle, 0);
	r = libusb_get_string_descriptor_ascii(handle, desc.iSerialNumber, striSerialNumber, 64); // �������� �����
	printf("  Serial number: %s\n", striSerialNumber);
	r = libusb_get_string_descriptor_ascii(handle, desc.iManufacturer, striManufacturer, 64); // �������������
	printf("  Vendor: %s\n", striManufacturer);
	r = libusb_get_string_descriptor_ascii(handle, desc.iProduct, striProduct, 64); // �������
	printf("  Product: %s\n", striProduct);
	for (int i = 0; i < (int)config->bNumInterfaces; i++)
	{
		inter = &config->interface[i];
		printf("    Number of alternate settings: %d\n", inter->num_altsetting); // ���������� �������������� ��������
		printf("    Device Class: %d\n", (int)desc.bDeviceClass); // ����� ����������
		for (int j = 0; j < inter->num_altsetting; j++)
		{
			interdesc = &inter->altsetting[j];
			printf("      Interface Number: %d\n", (int)interdesc->bInterfaceNumber); //  ����� ����������
			printf("      Number of endpoints: %d\n", (int)interdesc->bNumEndpoints); // ���������� �������� �����
			for (int k = 0; k < (int)interdesc->bNumEndpoints; k++)
			{
				epdesc = &interdesc->endpoint[k];
				printf("        Descriptor Type: %d\n", (int)epdesc->bDescriptorType); // ��� �����������
				printf("        EP Address: %d\n", (int)epdesc->bEndpointAddress); // ����� �������� �����
			}
		}
	}
	printf("-----------------------------------------------------------\n");
	libusb_free_config_descriptor(config);
}

int main()
{
	libusb_device** devs; // ��������� �� ��������� �� ����������, ������������ ��� ��������� ������ ���������
	libusb_context* ctx = NULL; // �������� ������ libusb
	int r; // ��� ������������ ��������
	ssize_t cnt; // ����� ��������� USB-���������
	ssize_t i; // ��������� ���������� ����� �������� ���� ���������
	r = libusb_init(&ctx); // ���������������� ���������� libusb, ������� ������ ������ � libusb
	if (r < 0)
	{
		fprintf(stderr, "Error: initialization failed, code: %d.\n", r);
		return 1;
	}
	libusb_set_debug(ctx, 3); // ������ ������� ����������� ���������� ���������
	cnt = libusb_get_device_list(ctx, &devs); // �������� ������ ���� ��������� USB- ���������
	if (cnt < 0)
	{
		fprintf(stderr, "Error: list of USB devices not received: %d.\n", r);
		return 1;
	}
	printf("Devices found: %d\n", (int)cnt);
	printf("===========================================================\n");
	/*printf("* Number of device configurations: \n");
	printf("   | * Device class: \n");
	printf("   |  | * Vendor ID: \n");
	printf("   |  |    | * Product ID: \n");
	printf("   |  |    |    | * Number of device interfaces\n");
	printf("   |  |    |    |   | * ���������� �������������� ��������\n");
	printf("   |  |    |    |   |  | * ����� ����������\n");
	printf("   |  |    |    |   |  |  | * ����� ����������\n");
	printf("   |  |    |    |   |  |  |  | * ���������� �������� �����\n");
	printf("   |  |    |    |   |  |  |  |  | * ��� �����������\n");
	printf("   |  |    |    |   |  |  |  |  |  | * ����� �������� �����\n");
	printf("+--+--+----+----+---+--+--+--+--+--+----------------------\n");*/
	for (i = 0; i < cnt; i++) // ���� �������� ���� ���������
	{
		printf("Device %d\n", (int)(i + 1));
		printdev(devs[i]); // ������ ���������� ����������
	}
	printf("===========================================================\n");
	libusb_free_device_list(devs, 1); // ���������� ������, ���������� �������� ��������� ������ ���������
	libusb_exit(ctx); // ��������� ������ � ����������� libusb, ������� ������ ������ � libusb
	return 0;
}

//http://libusb.sourceforge.net/api-1.0/group__libusb__dev.html
//https://www.dreamincode.net/forums/topic/148707-introduction-to-using-libusb-10/?__cf_chl_captcha_tk__=f092f8ac7035c357df08c6c86f495c158f548ee4-1605611346-0-AT9nn9rs6RzNeS7IcSQ5dPjeCbHM70sG-Xy_oSdzub_VyS3hAmC3FjkMM0Ba3BRS2wADtIBBxwlbxdEZK5xVCbgs_fBqO1iM1Pd1pjsodMf9lGmxu9ykk_WTtfRWMp0kfpt-2s0mJwBEymbGCLrzNIR1co6kAowoCrDwtCPYUjA6KzJcWibX38V-egKqSm1w8dNUwCtYJsRg8WNvzEVEb7mGfGPXVMz5SYzDhVSZONwDNAlcupOwvI89cLTD0O0NcBI8PDBAViOE01XYN8DYO99sYr68w_yn3CGjUZvZ02wfturTWCyTuzkMzn-JkZEqwlEoOEW7MHVqgM4f8hcsjqYFxDuUkwj-OdRP-wiV7VphcUrRqNF_NxKFeN0V2tVzoP_123xD4AJ8DtWqg_kCD7HAZdZvIv0ceodMmlh75NxqtMZ5_00TiP7XTaqMt9uQo9MfTyMKiMkGOJjze1oI5qa_v4SddgcyIKJ0NiFJoUx7f96TfyN40DfCWnI8ETeCp89pDxtsvfAWYCU1DbzW-sqE57XmCG9-eaS_e5S3R6AUWEVzZO_vwnSaEsNsmzIwK9vf3yHFVzT0gNqft6rQgag
//http://www.freebsd.org.ru/developers-handbook/usb-dev.html