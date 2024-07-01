#include "global.h"

MFRC522 mfrc522(SS_PIN, RST_PIN);
bool isSetupMode = false;          // Biến để theo dõi trạng thái chế độ cài đặt
unsigned long buttonPressTime = 0; // Biến để theo dõi thời gian nhấn nút
Card registeredCards[MAX_CARDS];
int cardCount = 0; // Số lượng thẻ đã lưu
