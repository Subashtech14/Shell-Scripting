#!/bin/bash

PS3="Select a color: "

select color in Red Green Blue Quit
do
    case $color in
        "Red")
            echo "You chose Red."
            ;;
        "Green")
            echo "You chose Green."
            ;;
        "Blue")
            echo "You chose Blue."
            ;;
        "Quit")
            echo "Exiting..."
            break
            ;;
        *)
            echo "Invalid option. Please choose again."
            ;;
    esac
done
