import QtQuick
import a08GroupedProperties

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Inherited List Properties")

    FootballTeam {
        id: team1Id
        title: "Rayon Sports"
        coach: "Raul Shung"
        captain: Striker {
            name: "Captain"
            position: "Middle Field"
            playing: true
            details {
                height: 178
                weight: 76
                speed: 76
            }
        }

        players: [
            Striker {
                name: "Player1"
                position: "Striker"
                playing: true
                details {
                    height: 333
                    weight: 76
                    speed: 76
                }
            },
            Defender {
                name: "Player2"
                position: "Middle Field"
                playing: true
                details.height: 222
                details.weight: 67
                details.speed: 77
            },
            Defender {
                name: "Player3"
                position: "Defender"
                playing: true
            }
        ]
    }

    ListView {
        anchors.fill: parent
        model: team1Id.players
        delegate: Rectangle {
            width: parent.width
            height: 50
            border.width: 1
            border.color: "yellowgreen"
            color: "beige"

            Text {
                anchors.centerIn: parent
                text: name
                font.pointSize: 20
            }
        }
    }

    Component.onCompleted: {
        console.log("We have " + team1Id.players.length + " players in team " + team1Id.title)
        console.log(team1Id.players[0].details.height)
    }
}
