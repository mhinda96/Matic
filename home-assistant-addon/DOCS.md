# Home Assistant Add-on: RaspberryMatic CCU

This add-on provides all features of a standard, e.g. RaspberryPi, Tinkerboard or
even virtual (e.g. OVA) based RaspberryMatic CCU system to be used as a HomeMatic or
homematicIP IoT central which is fully compatible to a CCU3 device.

## Installation

Follow these steps to install the add-on within your Home Assistant system:

1. Navigate in your Home Assistant frontend to **Settings** -> **Add-ons** -> **Add-on Store**.
2. Click on the vertical "⋮" dots on the top-right corner and select **Repositories**.
3. Enter the URL <https://github.com/jens-maus/RaspberryMatic> as a new add-on repository and click **Add** and **Close**.
4. Find the "RaspberryMatic CCU" add-on at the bottom of the add-on list and select it..
5. Click on the `INSTALL` button.
6. Install the add-on to the sidebar by clicking on `Show in sidebar`.
7. Start add-on by clicking on `START`
8. Click on the `RaspberryMatic` sidebar link to switch into the RaspberryMatic WebUI.

More detailed documentation on the installation and how to communicate with your HomeMatic/homematicIP devices
can be found in the official [RaspberryMatic documentation](https://github.com/jens-maus/RaspberryMatic/wiki/Installation-HomeAssistant)

## How to use

After installation you can configure the add-on to add a "RaspberryMatic" link
to the sidebar of your Home Assistant user interface. After having done so, this link can
be used to access the standard RaspberryMatic CCU WebUI to configure/setup your
HomeMatic/homematicIP devices in the usual CCU like way.

## HomeMatic/homematicIP device integration

After the RaspberryMatic CCU add-on has been correctly installed and your RaspberryMatic CCU WebUI shows existing HomeMatic/homematicIP devices, you still have to install and setup the general "HomeMatic integration". Only this step will bring up/integrate your HomeMatic/homematicIP devices - which the RaspberryMatic CCU add-on shows - in the Home Assistant user interface, thus making them usable within the context of Home Assistant.

For this to happen, please follow the official RaspberryMatic documentation on the [HomeAssistant integration](https://github.com/jens-maus/RaspberryMatic/wiki/HomeAssistant-Integration).
