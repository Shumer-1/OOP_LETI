#ifndef MESSAGE
#define MESSAGE

enum MessageState{
    MessageWinState,
    MessageLoseState,
    MessageGameState,
    MessageControlKeyState,
    MessageUselessKeyState
};


class Message{
    public:
    MessageState virtual getMessageState() = 0; 
};
#endif