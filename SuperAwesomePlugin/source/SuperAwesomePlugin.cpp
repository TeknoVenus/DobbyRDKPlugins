/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2021 Sky UK
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "SuperAwesomePlugin.h"

/**
 * Need to do this at the start of every plugin to make sure the correct
 * C methods are visible to allow PluginLauncher to find the plugin
 */
REGISTER_RDK_PLUGIN(SuperAwesomePlugin);

/**
 * @brief Constructor - called when plugin is loaded by PluginLauncher
 *
 * Do not change the parameters for this constructor - must match C methods
 * created by REGISTER_RDK_PLUGIN macro
 *
 * Note plugin name is not case sensitive
 */
SuperAwesomePlugin::SuperAwesomePlugin(std::shared_ptr<rt_dobby_schema> &containerConfig,
                                       const std::shared_ptr<DobbyRdkPluginUtils> &utils,
                                       const std::string &rootfsPath)
    : mName("MySuperAwesomePlugin"),
      mContainerConfig(containerConfig),
      mRootfsPath(rootfsPath),
      mUtils(utils)
{
    AI_LOG_FN_ENTRY();

    AI_LOG_FN_EXIT();
}

/**
 * @brief Set the bit flags for which hooks we're going to use
 *
 * This plugin uses all the hooks so set all the flags
 */
unsigned SuperAwesomePlugin::hookHints() const
{
    return (
        IDobbyRdkPlugin::HintFlags::PostInstallationFlag |
        IDobbyRdkPlugin::HintFlags::PreCreationFlag |
        IDobbyRdkPlugin::HintFlags::CreateRuntimeFlag |
        IDobbyRdkPlugin::HintFlags::CreateContainerFlag |
#ifdef USE_STARTCONTAINER_HOOK
        IDobbyRdkPlugin::HintFlags::StartContainerFlag |
#endif
        IDobbyRdkPlugin::HintFlags::PostStartFlag |
        IDobbyRdkPlugin::HintFlags::PostHaltFlag |
        IDobbyRdkPlugin::HintFlags::PostStopFlag);
}

// Begin Hook Methods

/**
 * @brief Dobby Hook - run in host namespace *once* when container bundle is downloaded
 */
bool SuperAwesomePlugin::postInstallation()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

/**
 * @brief Dobby Hook - run in host namespace before container creation process
 */
bool SuperAwesomePlugin::preCreation()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

/**
 * @brief OCI Hook - Run in host namespace
 */
bool SuperAwesomePlugin::createRuntime()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

/**
 * @brief OCI Hook - Run in container namespace. Paths resolve to host namespace
 */
bool SuperAwesomePlugin::createContainer()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

#ifdef USE_STARTCONTAINER_HOOK
/**
 * @brief OCI Hook - Run in container namespace
 */
bool SuperAwesomePlugin::startContainer()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    return true;
}
#endif

/**
 * @brief OCI Hook - Run in host namespace once container has started
 */
bool SuperAwesomePlugin::postStart()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

/**
 * @brief Dobby Hook - Run in host namespace when container terminates
 */
bool SuperAwesomePlugin::postHalt()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

/**
 * @brief OCI Hook - Run in host namespace. Confusing name - is run when a container is DELETED
 */
bool SuperAwesomePlugin::postStop()
{
    AI_LOG_INFO("Hello world, this is the %s hook", __func__);

    if (!mContainerConfig)
    {
        AI_LOG_WARN("Container config is null");
        return false;
    }

    AI_LOG_INFO("This hook is running for container with hostname %s", mUtils->getContainerId().c_str());
    AI_LOG_INFO(">>> %s", mContainerConfig->rdk_plugins->mysuperawesomeplugin->data->my_string);
    return true;
}

// End hook methods

/**
 * @brief Should return the names of the plugins this plugin depends on.
 *
 * This can be used to determine the order in which the plugins should be
 * processed when running hooks.
 *
 * @return Names of the plugins this plugin depends on.
 */
std::vector<std::string> SuperAwesomePlugin::getDependencies() const
{
    std::vector<std::string> dependencies;
    const rt_schema_my_super_awesome_plugin *pluginConfig = mContainerConfig->rdk_plugins->mysuperawesomeplugin;

    for (size_t i = 0; i < pluginConfig->depends_on_len; i++)
    {
        dependencies.push_back(pluginConfig->depends_on[i]);
    }

    return dependencies;
}

// Begin private methods
