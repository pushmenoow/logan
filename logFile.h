#define LOGFILE_H
#include <QString>

//объявление структуры для хранения записей
struct logFile
{
    QString date;			//Date
    QString time;			//Time
    QString c_ip;			//Client IP Address
    QString cs_username;	//User Name
    QString cs_host;		//Host
    QString s_port;         //Server Port
    QString cs_method;		//Method
    QString cs_uri_stem;	//URI Stem
    QString sc_status;		//Protocol Status
    QString sc_win32_stat;  //Win32 Status
    QString sc_substatus;	//Protocol Substatus
    QString sc_bytes;		//Bytes Sent
    QString cs_bytes;		//Bytes Received
    QString time_taken; 	//Time Taken
    QString x_fullpath; 	//Full Path
    QString x_debug;		//Additional Information

    //disabled attributes
    QString s_sitename;		//Service Name
    QString s_computername;	//Server Name
    QString s_ip;           //Server IP Address
    QString x_session;		//Session ID
    QString c_port;			//Client Port

    //reserve for search
    QString attr;
};
