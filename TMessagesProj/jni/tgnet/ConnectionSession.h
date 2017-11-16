/*
 * This is the source code of tgnet library v. 1.0
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Nikolai Kudashov, 2015.
 */

#ifndef CONNECTIONSESSION_H
#define CONNECTIONSESSION_H

#include <stdint.h>
#include <vector>
#include "Defines.h"

class ConnectionSession {

public:
    void recreateSession();
    void genereateNewSessionId();
    void setSessionId(int64_t id);
    int64_t getSissionId();
    uint32_t generateMessageSeqNo(bool increment);
    bool isMessageIdProcessed(int64_t messageId);
    void addProcessedMessageId(int64_t messageId);
    bool hasMessagesToConfirm();
    void addMessageToConfirm(int64_t messageId);
    NetworkMessage *generateConfirmationRequest();
    bool isSessionProcessed(int64_t sessionId);
    void addProcessedSession(int64_t sessionId);

private:
    int64_t sessionId;
    uint32_t nextSeqNo = 0;
    int64_t minProcessedMessageId = 0;

    std::vector<int64_t> processedMessageIds;
    std::vector<int64_t> messagesIdsForConfirmation;
    std::vector<int64_t> processedSessionChanges;
};


#endif
