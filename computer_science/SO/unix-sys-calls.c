#include <stdio.h> // scanf e printf
#include <string.h> // stringhe
#include <stdlib.h> // libreria standard

void environment() {
  /*
  echo $SHELL
  /bin/bash

  variabili accessibili tramite char** environ
  */
}

void process() {
  #include <unistd.h>
  #include <sys/wait.h>
  int pid = getpid();  // process ID
  int ppid = getppid(); // parent process ID
  //ogni processo ha un status in base a cosa sta facendo

  int i = fork(); // torna -1 errore, 0 nel figlio, pid figlio nel padre
  switch(i) {
    case -1 : break; // Errore
    case 0 : break;  // codice figlio
    default : break; // codice padre
  }

  atexit(function_name); // funzione chiamata quando si usa exit()
  wait(&var); // aspetta che un figlio termina e scrive lo status in var
  // se un figlio ha gia' terminato ritorna subito
  // ritorna il pid oppure -1 in caso di errore (tipo che non ha figli)
  while ((childPid = wait(NULL)) != -1) continue; // attende la fine di tutti i figli
  if (errno != ECHILD) // errore inatteso errExit("wait"); // gestione errore...

  waitpid(pid_t pid,int *status,int options);
  /* pid {
    pid > 0 attende quel processo
    pid == 0 attende un figlio nello stesso process group del padre
    pid < -1 attende un figlio il cui process group e' +pid
    pid == -1 attende un figlio qualsiasi (come wait)
  }
  options {
    - WUNTRACED: oltre a restituire info quando un figlio termina,
        restituisci informazioni quando il figlio viene bloccato da un segnale.

    - WCONTINUED: restituisci informazioni anche nel caso il
        figlio sia stopped e venga risvegliato da un segnale SIGCONT.

    - WNOHANG: se nessun figlio specificato da pid ha cambiato stato, restituisci immediatamente,
        invece di bloccare il chiamante. In questo caso, il valore di ritorno di waitpid() è 0.
        Se il processo chiamante non ha figli con il pid richiesto,
        waitpid() fallisce con l'errore ECHILD.
  }
  status {
    <sys/wait.h>
  }
  */
  #include <signal.h>
  SIGCHILD handler = funzione chiamata quando un figlo termina
  int sigaction(int sig, const struct sigaction *act, struct sigaction *oact);
  /* returns 0 for success and -1 for error */

  int execve(const char *pathname, char *const argv[], char *const envp[]);
  /*
  carica un nuovo programma(percorso,argomenti,variabili d'ambiente)
  nel processo cancellando i dati precedenti. ritorna -1 se Errore
  */

  errno = variabile di errore;
  system("ls"); // crea un processo che esegue un comando su shell
}

void segnali() {
  #include <signal.h>
  trap = segnali da un processo a se stesso
  interrupt = segnali da un processo a un altro

  void (*signal(int sig, void (*handler)(int))) (int);

  signal(segnale, SIG_DFL); // associa l'azione di default
  signal(segnale, SIG_IGN); // ignora il segnale

  /* sig = segnale
  handler = funzione void f(int)
  ritorna la funzione handler precedente (che prende un intero) */

  pause(); // aspetta un segnale

  struct sigaction {
    void (* sa_handler ) ( int signum );  // funzione di handling
    sigset_t sa_mask;   // segnali bloccati durante l'esecuzione dell'handler
    int sa_flags;   // maschera bitwise per modificare il la gestione del segnale {
      SA_NODEFER = permette nested invocations dello stesso segnale
    }
    // plus others (for advanced users )
  };

  int sigaction ( int signum , const struct sigaction * act, struct sigaction * oldact );

  int kill(pid_t pid, int sig); /* 0 on success, -1 on error {
    pid > 0: quel processo;
    pid == 0: tutti i processi del gruppo del chiamante, chiamante compreso
    pid < -1: tutti i processi del gruppo di +pid;
    pid == -1: (broadcast signal) il segnale è inviato a tutti i processi per i quali
      il processo ha i permessi di inviare un segnale, eccetto init (che ha pid 1) ed
      il chiamante. Se l'utente non è super user, il segnale è inviato a tutti i
      processi con stesso uid dell'utente, escluso il processo che invia il segnale
  }
  se sig == 0 (nessun segnale) si controlla se il processo esiste e si possono mandare segnali {
    errno = ESRCH (no such process);
    errno = EPERM (no permission to send signals);
  } */
}

void pipe() {
  #include <unistd.h>
  int pipe(int filedes[2]); // returns 0 for success -1 for error
  // filedes = due descrittori file
  // 0 per lettura 1 per scrittura
  per comunicare crea la pipe e poi forka cosi il figlio ha i descrittori
  poi ognuno chiude il file che non usa


  #include <stdio.h>
  FILE *popen(const char *command, const char *mode); /* Returns file stream, or NULL on error {
    crea pipe, esegue command su un nuovo processo che ha stdin o stdout come pipe
    mode = 'r' se il nuovo processo scrive stdout sul pipe
    mode = 'w' se il nuovo processo legge stdin dal pipe
  } */

  int pclose(FILE *stream); /* Returns termination status of child process, or -1 on error
    attende che il processo figlio termini */
}

void fifo() {
  // per processi non imparentati
  // su shell
  // $ mkfifo [ -m mode ] pathname
  // mode = permessi
  // tee <file> in una pipeline per duplicare l'output sul file
  #include <sys/stat.h>
  int mkfifo(const char *pathname, mode_t mode);  // 0 on success, -1 on error
  mode = OR di una serie di costanti per i permessi

}

void messages() {
  int get(key_t key,mode_t permissions);
  msgget()
  semget()
  shmget()
  id = msgget(key, IPC_CREAT /*per creare l'oggetto */);
  /* returns the id of the object, -1 on error
  IPC_CREAT = per creare l'oggetto
  IPC_EXCL = garantisce che il processo sia il creatore */

  ctl(id,mode,NULL) { /* control
    IPC_RMID = cancella l'oggetto
  }
  quando creo un oggetto con
  key = IPC_PRIVATE; non devo specificare IPC_CREAT e IPC_EXCL
  */

  #include <sys/ipc.h>
  key_t ftok(char *pathname, int proj); // returns key on success, -1 on error

  $ ipcs = ls
  $ ipcrm = rm

  #include <sys/msg.h>

  int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
  /* msgflg = IPC_NOWAIT per non bloccare se la coda e' piena e non invia il messaggio

  msgp =
  struct mymsg {
    long mtype; Message type
    char mtext[]; Message body
  }
  msgsz = struct size minus mtype
  */

  size_t msgrcv(int msqid, void *msgp, size_t maxmsgsz, long msgtyp, int msgflg);
  /* returns number of bytes copied into mtext field
  maxmsgsz = max lunghezza, se superata non viene ricevuto il messaggio e rimane in coda
  msgtyp = 0 per il primo messaggio,
          > 0 == mtype
          < 0 = mtype <= +msgtyp
  msgflg = IPC_NOWAIT = non-blocking
          MSG_NOERROR = se maxmsgsz e' superato, riceve quella parte del messaggio e il resto va perso
  */

  int msgctl(int msqid, int cmd, struct msqid_ds *buf);
  /*
  cmd = OR {
    IPC_RMID = rimuove la coda
    IPC_STAT = copia la struttura della coda (msqid_ds) in buf
    IPC_SET = setta la struttura con quello che c'e' in buf
  }
  */

  struct msqid_ds {
    struct ipc_perm msg_perm; /*Ownership e permissions */
    time_t msg_stime; /* Time of last msgsnd() */
    time_t msg_rtime; /* Time of last msgrcv() */
    time_t msg_ctime; /* Time of last change */
    unsigned long __msg_cbytes; /* Number of bytes in queue*/
    msgqnum_t msg_qnum; /* Number of messages in queue */
    msglen_t msg_qbytes; /* Maximum bytes in queue */
    pid_t msg_lspid; /* PID of last msgsnd() */
    pid_t msg_lrpid; /* PID of last msgrcv() */
  }

  struct ipc_perm {
    key_t key;
    uid_t uid; /* ushort: Owner's user ID */
    gid_t gid; /* ushort: Owner's group ID */
    uid_t cuid; /* Creator's user ID */
    gid_t cgid; /* Creator's group ID */
    unsigned short mode; /* permissions */
    unsigned short __seq; /*Sequence number*/
  };
}

int main(){}
