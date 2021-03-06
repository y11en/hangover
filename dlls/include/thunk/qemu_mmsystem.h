#ifndef HAVE_QEMU_THUNK_MMSYSTEM_H
#define HAVE_QEMU_THUNK_MMSYSTEM_H

struct qemu_WAVEHDR
{
    qemu_ptr    lpData;
    DWORD       dwBufferLength;
    DWORD       dwBytesRecorded;
    qemu_ptr    dwUser;
    DWORD       dwFlags;
    DWORD       dwLoops;
    qemu_ptr    lpNext;
    qemu_ptr    reserved;
};

static inline void WAVEHDR_g2h(WAVEHDR *host, const struct qemu_WAVEHDR *guest)
{
    host->lpData = (char *)(ULONG_PTR)guest->lpData;
    host->dwBufferLength = guest->dwBufferLength;
    host->dwBytesRecorded = guest->dwBytesRecorded;
    host->dwUser = guest->dwUser;
    host->dwFlags = guest->dwFlags;
    host->dwLoops = guest->dwLoops;
    host->lpNext = (WAVEHDR *)(ULONG_PTR)guest->lpNext; /* Note: MSDN says "reserved" */
    host->reserved = guest->reserved;
}

static inline void WAVEHDR_h2g(struct qemu_WAVEHDR *guest, const WAVEHDR *host)
{
    guest->lpData = (ULONG_PTR)host->lpData;
    guest->dwBufferLength = host->dwBufferLength;
    guest->dwBytesRecorded = host->dwBytesRecorded;
    guest->dwUser = host->dwUser;
    guest->dwFlags = host->dwFlags;
    guest->dwLoops = host->dwLoops;
    guest->lpNext = (ULONG_PTR)host->lpNext; /* Note: MSDN says "reserved" */
    guest->reserved = host->reserved;
}

struct qemu_MIXERLINEA
{
    DWORD       cbStruct;
    DWORD       dwDestination;
    DWORD       dwSource;
    DWORD       dwLineID;
    DWORD       fdwLine;
    qemu_ptr    dwUser;
    DWORD       dwComponentType;
    DWORD       cChannels;
    DWORD       cConnections;
    DWORD       cControls;
    CHAR        szShortName[MIXER_SHORT_NAME_CHARS];
    CHAR        szName[MIXER_LONG_NAME_CHARS];
    struct
    {
        DWORD       dwType;
        DWORD       dwDeviceID;
        WORD        wMid;
        WORD        wPid;
        MMVERSION   vDriverVersion;
        CHAR        szPname[MAXPNAMELEN];
    } Target;
};

static inline void MIXERLINEA_g2h(MIXERLINEA *host, const struct qemu_MIXERLINEA *guest)
{
    host->cbStruct = sizeof(*host);
    host->dwDestination = guest->dwDestination;
    host->dwSource = guest->dwSource;
    host->dwLineID = guest->dwLineID;
    host->fdwLine = guest->fdwLine;
    host->dwUser = guest->dwUser;
    host->dwComponentType = guest->dwComponentType;
    host->cChannels = guest->cChannels;
    host->cConnections = guest->cConnections;
    host->cControls = guest->cControls;
    memcpy(host->szShortName, guest->szShortName, sizeof(host->szShortName));
    memcpy(host->szName, guest->szName, sizeof(host->szName));

    host->Target.dwType = guest->Target.dwType;
    host->Target.dwDeviceID = guest->Target.dwDeviceID;
    host->Target.wMid = guest->Target.wMid;
    host->Target.wPid = guest->Target.wPid;
    host->Target.vDriverVersion = guest->Target.vDriverVersion;
    memcpy(host->Target.szPname, guest->Target.szPname, sizeof(host->Target.szPname));
}

static inline void MIXERLINEA_h2g(struct qemu_MIXERLINEA *guest, const MIXERLINEA *host)
{
    guest->dwDestination = host->dwDestination;
    guest->dwSource = host->dwSource;
    guest->dwLineID = host->dwLineID;
    guest->fdwLine = host->fdwLine;
    guest->dwUser = host->dwUser;
    guest->dwComponentType = host->dwComponentType;
    guest->cChannels = host->cChannels;
    guest->cConnections = host->cConnections;
    guest->cControls = host->cControls;
    memcpy(guest->szShortName, host->szShortName, sizeof(guest->szShortName));
    memcpy(guest->szName, host->szName, sizeof(guest->szName));

    guest->Target.dwType = host->Target.dwType;
    guest->Target.dwDeviceID = host->Target.dwDeviceID;
    guest->Target.wMid = host->Target.wMid;
    guest->Target.wPid = host->Target.wPid;
    guest->Target.vDriverVersion = host->Target.vDriverVersion;
    memcpy(guest->Target.szPname, host->Target.szPname, sizeof(guest->Target.szPname));
}

struct qemu_MIXERLINEW
{
    DWORD       cbStruct;
    DWORD       dwDestination;
    DWORD       dwSource;
    DWORD       dwLineID;
    DWORD       fdwLine;
    qemu_ptr    dwUser;
    DWORD       dwComponentType;
    DWORD       cChannels;
    DWORD       cConnections;
    DWORD       cControls;
    WCHAR       szShortName[MIXER_SHORT_NAME_CHARS];
    WCHAR       szName[MIXER_LONG_NAME_CHARS];
    struct
    {
        DWORD       dwType;
        DWORD       dwDeviceID;
        WORD        wMid;
        WORD        wPid;
        MMVERSION   vDriverVersion;
        WCHAR       szPname[MAXPNAMELEN];
    } Target;
};

static inline void MIXERLINEW_g2h(MIXERLINEW *host, const struct qemu_MIXERLINEW *guest)
{
    host->cbStruct = sizeof(*host);
    host->dwDestination = guest->dwDestination;
    host->dwSource = guest->dwSource;
    host->dwLineID = guest->dwLineID;
    host->fdwLine = guest->fdwLine;
    host->dwUser = guest->dwUser;
    host->dwComponentType = guest->dwComponentType;
    host->cChannels = guest->cChannels;
    host->cConnections = guest->cConnections;
    host->cControls = guest->cControls;
    memcpy(host->szShortName, guest->szShortName, sizeof(host->szShortName));
    memcpy(host->szName, guest->szName, sizeof(host->szName));

    host->Target.dwType = guest->Target.dwType;
    host->Target.dwDeviceID = guest->Target.dwDeviceID;
    host->Target.wMid = guest->Target.wMid;
    host->Target.wPid = guest->Target.wPid;
    host->Target.vDriverVersion = guest->Target.vDriverVersion;
    memcpy(host->Target.szPname, guest->Target.szPname, sizeof(host->Target.szPname));
}

static inline void MIXERLINEW_h2g(struct qemu_MIXERLINEW *guest, const MIXERLINEW *host)
{
    guest->dwDestination = host->dwDestination;
    guest->dwSource = host->dwSource;
    guest->dwLineID = host->dwLineID;
    guest->fdwLine = host->fdwLine;
    guest->dwUser = host->dwUser;
    guest->dwComponentType = host->dwComponentType;
    guest->cChannels = host->cChannels;
    guest->cConnections = host->cConnections;
    guest->cControls = host->cControls;
    memcpy(guest->szShortName, host->szShortName, sizeof(guest->szShortName));
    memcpy(guest->szName, host->szName, sizeof(guest->szName));

    guest->Target.dwType = host->Target.dwType;
    guest->Target.dwDeviceID = host->Target.dwDeviceID;
    guest->Target.wMid = host->Target.wMid;
    guest->Target.wPid = host->Target.wPid;
    guest->Target.vDriverVersion = host->Target.vDriverVersion;
    memcpy(guest->Target.szPname, host->Target.szPname, sizeof(guest->Target.szPname));
}

struct qemu_MIXERLINECONTROLS
{
    DWORD       cbStruct;
    DWORD       dwLineID;
    union
    {
        DWORD   dwControlID;
        DWORD   dwControlType;
    } DUMMYUNIONNAME;
    DWORD       cControls;
    DWORD       cbmxctrl;
    qemu_ptr    pamxctrl;
};

static inline void MIXERLINECONTROLS_g2h(MIXERLINECONTROLSW *host, const struct qemu_MIXERLINECONTROLS *guest)
{
    host->cbStruct = sizeof(*host);
    host->dwLineID = guest->dwLineID;
    host->dwControlID = guest->dwControlID;
    host->cControls = guest->cControls;
    host->cbmxctrl = guest->cbmxctrl;
    host->pamxctrl = (MIXERCONTROLW *)(ULONG_PTR)guest->pamxctrl;
}

static inline void MIXERLINECONTROLS_h2g(struct qemu_MIXERLINECONTROLS *guest, const MIXERLINECONTROLSW *host)
{
    guest->dwLineID = host->dwLineID;
    guest->dwControlID = host->dwControlID;
    guest->cControls = host->cControls;
    guest->cbmxctrl = host->cbmxctrl;
    guest->pamxctrl = (ULONG_PTR)host->pamxctrl;
}

struct qemu_MIXERCONTROLDETAILS
{
    DWORD           cbStruct;
    DWORD           dwControlID;
    DWORD           cChannels;
    union
    {
        qemu_ptr    hwndOwner;
        DWORD       cMultipleItems;
    } DUMMYUNIONNAME;
    DWORD           cbDetails;
    qemu_ptr        paDetails; /* This can hold pointers to different structs, but they are all compatible. */
};

static inline void MIXERCONTROLDETAILS_g2h(MIXERCONTROLDETAILS *host, const struct qemu_MIXERCONTROLDETAILS *guest)
{
    host->cbStruct = sizeof(*host);
    host->dwControlID = guest->dwControlID;
    host->cChannels = guest->cChannels;
    host->hwndOwner = (HWND)(ULONG_PTR)guest->hwndOwner;
    host->cbDetails = guest->cbDetails;
    host->paDetails = (void *)(ULONG_PTR)guest->paDetails;
}

static inline void MIXERCONTROLDETAILS_h2g(struct qemu_MIXERCONTROLDETAILS *guest, const MIXERCONTROLDETAILS *host)
{
    guest->dwControlID = host->dwControlID;
    guest->cChannels = host->cChannels;
    guest->hwndOwner = (ULONG_PTR)host->hwndOwner;
    guest->cbDetails = host->cbDetails;
    guest->paDetails = (ULONG_PTR)host->paDetails;
}

struct qemu_MMIOINFO
{
    DWORD       dwFlags;
    FOURCC      fccIOProc;
    qemu_ptr    pIOProc;
    UINT        wErrorRet;
    qemu_ptr    hTask;
    /* fields maintained by MMIO functions during buffered I/O */
    LONG        cchBuffer;
    qemu_ptr    pchBuffer;
    qemu_ptr    pchNext;
    qemu_ptr    pchEndRead;
    qemu_ptr    pchEndWrite;
    LONG        lBufOffset;
    /* fields maintained by I/O procedure */
    LONG        lDiskOffset;
    DWORD       adwInfo[3];
    /* other fields maintained by MMIO */
    DWORD       dwReserved1;
    DWORD       dwReserved2;
    qemu_ptr    hmmio;
};

#ifndef QEMU_DLL_GUEST
static inline void MMIOINFO_g2h(MMIOINFO *host, const struct qemu_MMIOINFO *guest)
{
    host->dwFlags = guest->dwFlags;
    host->fccIOProc = guest->fccIOProc;
    host->pIOProc = (LPMMIOPROC)(ULONG_PTR)guest->pIOProc;
    host->wErrorRet = guest->wErrorRet;
    host->hTask = (HTASK)(ULONG_PTR)guest->hTask;
    host->cchBuffer = guest->cchBuffer;
    host->pchBuffer = (HPSTR)(ULONG_PTR)guest->pchBuffer;
    host->pchNext = (HPSTR)(ULONG_PTR)guest->pchNext;
    host->pchEndRead = (HPSTR)(ULONG_PTR)guest->pchEndRead;
    host->pchEndWrite = (HPSTR)(ULONG_PTR)guest->pchEndWrite;
    host->lBufOffset = guest->lBufOffset;
    host->lDiskOffset = guest->lDiskOffset;
    host->adwInfo[0] = guest->adwInfo[0];
    host->adwInfo[1] = guest->adwInfo[1];
    host->adwInfo[2] = guest->adwInfo[2];
    host->dwReserved1 = guest->dwReserved1;
    host->dwReserved2 = guest->dwReserved2;
    host->hmmio = (HMMIO)(ULONG_PTR)guest->hmmio;
}

static inline void MMIOINFO_h2g(struct qemu_MMIOINFO *guest, const MMIOINFO *host)
{
    guest->dwFlags = host->dwFlags;
    guest->fccIOProc = host->fccIOProc;
    guest->pIOProc = (ULONG_PTR)host->pIOProc;
    guest->wErrorRet = host->wErrorRet;
    guest->hTask = (ULONG_PTR)host->hTask;
    guest->cchBuffer = host->cchBuffer;
    guest->pchBuffer = (ULONG_PTR)host->pchBuffer;
    guest->pchNext = (ULONG_PTR)host->pchNext;
    guest->pchEndRead = (ULONG_PTR)host->pchEndRead;
    guest->pchEndWrite = (ULONG_PTR)host->pchEndWrite;
    guest->lBufOffset = host->lBufOffset;
    guest->lDiskOffset = host->lDiskOffset;
    guest->adwInfo[0] = host->adwInfo[0];
    guest->adwInfo[1] = host->adwInfo[1];
    guest->adwInfo[2] = host->adwInfo[2];
    guest->dwReserved1 = host->dwReserved1;
    guest->dwReserved2 = host->dwReserved2;
    guest->hmmio = (ULONG_PTR)host->hmmio;
}
#endif

struct qemu_MCI_GETDEVCAPS_PARMS
{
    qemu_ptr    dwCallback;
    DWORD       dwReturn;
    DWORD       dwItem;
};

static inline void MCI_GETDEVCAPS_PARMS_g2h(MCI_GETDEVCAPS_PARMS *host, const struct qemu_MCI_GETDEVCAPS_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->dwReturn = guest->dwReturn;
    host->dwItem = guest->dwItem;
}

static inline void MCI_GETDEVCAPS_PARMS_h2g(struct qemu_MCI_GETDEVCAPS_PARMS *guest, const MCI_GETDEVCAPS_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwReturn = host->dwReturn;
    guest->dwItem = host->dwItem;
}

struct qemu_MCI_SAVE_PARMS
{
    qemu_ptr  dwCallback;
    qemu_ptr  lpfilename;
};

static inline void MCI_SAVE_PARMS_g2h(MCI_SAVE_PARMSW *host, const struct qemu_MCI_SAVE_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->lpfilename = (WCHAR *)(ULONG_PTR)guest->lpfilename;
}

static inline void MCI_SAVE_PARMS_h2g(struct qemu_MCI_SAVE_PARMS *guest, const MCI_SAVE_PARMSW *host)
{
    guest->dwCallback = host->dwCallback;
    guest->lpfilename = (ULONG_PTR)host->lpfilename;
}

struct qemu_MCI_RECORD_PARMS
{
    qemu_ptr    dwCallback;
    DWORD       dwFrom;
    DWORD       dwTo;
};

static inline void MCI_RECORD_PARMS_g2h(MCI_RECORD_PARMS *host, const struct qemu_MCI_RECORD_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->dwFrom = guest->dwFrom;
    host->dwTo = guest->dwTo;
}

static inline void MCI_RECORD_PARMS_h2g(struct qemu_MCI_RECORD_PARMS *guest, const MCI_RECORD_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwFrom = host->dwFrom;
    guest->dwTo = host->dwTo;
}

struct qemu_MCI_STATUS_PARMS
{
    qemu_ptr    dwCallback;
    qemu_ptr    dwReturn;
    DWORD       dwItem;
    DWORD       dwTrack;
};

static inline void MCI_STATUS_PARMS_g2h(MCI_STATUS_PARMS *host, const struct qemu_MCI_STATUS_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->dwReturn = guest->dwReturn;
    host->dwItem = guest->dwItem;
    host->dwTrack = guest->dwTrack;
}

static inline void MCI_STATUS_PARMS_h2g(struct qemu_MCI_STATUS_PARMS *guest, const MCI_STATUS_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwReturn = host->dwReturn;
    guest->dwItem = host->dwItem;
    guest->dwTrack = host->dwTrack;
}

struct qemu_MCI_OPEN_PARMS
{
    qemu_ptr    dwCallback;
    MCIDEVICEID wDeviceID;
    qemu_ptr    lpstrDeviceType;
    qemu_ptr    lpstrElementName;
    qemu_ptr    lpstrAlias;
};

static inline void MCI_OPEN_PARMS_g2h(MCI_OPEN_PARMSW *host, const struct qemu_MCI_OPEN_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->wDeviceID = guest->wDeviceID;
    host->lpstrDeviceType = (WCHAR *)(ULONG_PTR)guest->lpstrDeviceType;
    host->lpstrElementName = (WCHAR *)(ULONG_PTR)guest->lpstrElementName;
    host->lpstrAlias = (WCHAR *)(ULONG_PTR)guest->lpstrAlias;
}

static inline void MCI_OPEN_PARMS_h2g(struct qemu_MCI_OPEN_PARMS *guest, const MCI_OPEN_PARMSW *host)
{
    guest->dwCallback = host->dwCallback;
    guest->wDeviceID = host->wDeviceID;
    guest->lpstrDeviceType = (ULONG_PTR)host->lpstrDeviceType;
    guest->lpstrElementName = (ULONG_PTR)host->lpstrElementName;
    guest->lpstrAlias = (ULONG_PTR)host->lpstrAlias;
}

struct qemu_MCI_SET_PARMS
{
    qemu_ptr    dwCallback;
    DWORD       dwTimeFormat;
    DWORD       dwAudio;
    DWORD       extras[8]; /* See qemu_mciSendCommand in dlls/winmm/mci.c. */
};

static inline void MCI_SET_PARMS_g2h(MCI_SET_PARMS *host, const struct qemu_MCI_SET_PARMS *guest)
{
    unsigned int i;
    struct
    {
        MCI_SET_PARMS base;
        DWORD extras[8];
    } *host_ext = (void *)host;

    host->dwCallback = guest->dwCallback;
    host->dwTimeFormat = guest->dwTimeFormat;
    host->dwAudio = guest->dwAudio;

    for (i = 0; i < sizeof(guest->extras) / sizeof(*guest->extras); ++i)
        host_ext->extras[i] = guest->extras[i];
}

static inline void MCI_SET_PARMS_h2g(struct qemu_MCI_SET_PARMS *guest, const MCI_SET_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwTimeFormat = host->dwTimeFormat;
    guest->dwAudio = host->dwAudio;
}

struct qemu_MCI_PLAY_PARMS
{
    qemu_ptr    dwCallback;
    DWORD       dwFrom;
    DWORD       dwTo;
};

static inline void MCI_PLAY_PARMS_g2h(MCI_PLAY_PARMS *host, const struct qemu_MCI_PLAY_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->dwFrom = guest->dwFrom;
    host->dwTo = guest->dwTo;
}

static inline void MCI_PLAY_PARMS_h2g(struct qemu_MCI_PLAY_PARMS *guest, const MCI_PLAY_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwFrom = host->dwFrom;
    guest->dwTo = host->dwTo;
}

struct qemu_MCI_SYSINFO_PARMS
{
    qemu_ptr    dwCallback;
    qemu_ptr    lpstrReturn;
    DWORD       dwRetSize;
    DWORD       dwNumber;
    UINT        wDeviceType;
};

static inline void MCI_SYSINFO_PARMS_g2h(MCI_SYSINFO_PARMSW *host, const struct qemu_MCI_SYSINFO_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->lpstrReturn = (WCHAR *)(ULONG_PTR)guest->lpstrReturn;
    host->dwRetSize = guest->dwRetSize;
    host->dwNumber = guest->dwNumber;
    host->wDeviceType = guest->wDeviceType;
}

static inline void MCI_SYSINFO_PARMS_h2g(struct qemu_MCI_SYSINFO_PARMS *guest, const MCI_SYSINFO_PARMSW *host)
{
    guest->dwCallback = host->dwCallback;
    guest->lpstrReturn = (ULONG_PTR)host->lpstrReturn;
    guest->dwRetSize = host->dwRetSize;
    guest->dwNumber = host->dwNumber;
    guest->wDeviceType = host->wDeviceType;
}

struct qemu_MCI_INFO_PARMS
{
    qemu_ptr    dwCallback;
    qemu_ptr    lpstrReturn;
    DWORD       dwRetSize;
};

static inline void MCI_INFO_PARMS_g2h(MCI_INFO_PARMSW *host, const struct qemu_MCI_INFO_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->lpstrReturn = (WCHAR *)(ULONG_PTR)guest->lpstrReturn;
    host->dwRetSize = guest->dwRetSize;
}

static inline void MCI_INFO_PARMS_h2g(struct qemu_MCI_INFO_PARMS *guest, const MCI_INFO_PARMSW *host)
{
    guest->dwCallback = host->dwCallback;
    guest->lpstrReturn = (ULONG_PTR)host->lpstrReturn;
    guest->dwRetSize = host->dwRetSize;
}

struct qemu_MCI_SEEK_PARMS
{
    qemu_ptr    dwCallback;
    DWORD       dwTo;
};

static inline void MCI_SEEK_PARMS_g2h(MCI_SEEK_PARMS *host, const struct qemu_MCI_SEEK_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
    host->dwTo = guest->dwTo;
}

static inline void MCI_SEEK_PARMS_h2g(struct qemu_MCI_SEEK_PARMS *guest, const MCI_SEEK_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
    guest->dwTo = host->dwTo;
}

struct qemu_MCI_GENERIC_PARMS
{
    DWORD_PTR dwCallback;
};

static inline void MCI_GENERIC_PARMS_g2h(MCI_GENERIC_PARMS *host, const struct qemu_MCI_GENERIC_PARMS *guest)
{
    host->dwCallback = guest->dwCallback;
}

static inline void MCI_GENERIC_PARMS_h2g(struct qemu_MCI_GENERIC_PARMS *guest, const MCI_GENERIC_PARMS *host)
{
    guest->dwCallback = host->dwCallback;
}

#endif
