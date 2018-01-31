#ifndef NETWORKDEVICE_H
#define NETWORKDEVICE_H

#include <pcap.h>

namespace Util {
class NetworkDevice {
public:
    static void showAllDevices() {
        pcap_if_t *alldevs;
        pcap_if_t *d;
        int i = 0;
        char errbuf[PCAP_ERRBUF_SIZE];

        if (pcap_findalldevs(&alldevs, errbuf) == -1)
        {
            fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        }

        if (nullptr == alldevs)
        {
            printf("\n No interfaces found!\n");
        }
        else
        {
            d = alldevs;
            printf("All network devices:\n");
            while (nullptr != d)
            {
                printf("%d. name: %s", ++i, d->name);
                if (d->description)
                {
                    printf("; desc: %s\n", d->description);
                }
                else
                {
                    printf("; (No description available)\n");
                }
                d=d->next;
            }
            pcap_freealldevs(alldevs);
        }
    }
};


}



#endif // NETWORKDEVICE_H
