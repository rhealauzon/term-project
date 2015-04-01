#ifndef _CLIENTGAMESTATE_H_
#define _CLIENTGAMESTATE_H_

#include "../KeyListener.h"
#include "../../Network/Message.h"
#include "../../Network/Session.h"
#include "../../Network/NetworkEntity.h"

using Networking::NetworkEntity;
using Networking::Message;
using Networking::Session;

class GameScene;
class ClientLobbyScene;
class CommandEntity;

/**
 * the {PlayerEntity} is resides the server, and is logically mapped to the
 *   {CommandEntity} class over the network, which is on the client side.
 *
 * the client sends command using {CommandEntity::update} such as move commands
 *   or others like choosing their character to the Server. such commands are
 *   handled in the {PlayerEntity::onUpdate} method. and sent using the. .
 */
class ClientGameState : public NetworkEntity
{
    public:
        ClientGameState(int id, CommandEntity *command, GameScene *scene, ClientLobbyScene* lobbyScene);
        ~ClientGameState();

    protected:
        virtual void onUpdate(Message message);

    private:
        /**
         * pointer to the singleton {GameScene} instance.
         */
        GameScene* _gameScene;
        /**
         * pointer to the singleton {ClientLobbyScene} instance.
         */
        ClientLobbyScene* _lobbyScene;
        /**
         * pointer to the singleton {CommandEntity} instance.
         */
        CommandEntity* command;
};

#endif

