#ifndef PROTOCOL_H_
#define PROTOCOL_H_

void serialCom();
void debugmsg_append_str(const char *str);
void msp_push(uint8_t uart, uint8_t msp);
#endif /* PROTOCOL_H_ */
