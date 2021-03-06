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
/*
 * File: SuperAwesomePlugin.h
 *
 */
#ifndef SuperAwesomePlugin_H
#define SuperAwesomePlugin_H

#include <Dobby/rdkPlugins/RdkPluginBase.h>

#include <sys/types.h>
#include <netinet/in.h>

#include <unistd.h>
#include <string>
#include <memory>

/**
 * @brief Simple Dobby RDK Plugin
 *
 * Implements all hook points to print a simple statement showing the hook has been
 * called successfully.
 *
 * Can be used as a reference implementation for future plugins
 */
class SuperAwesomePlugin : public RdkPluginBase
{
public:
    SuperAwesomePlugin(std::shared_ptr<rt_dobby_schema>& containerConfig,
                  const std::shared_ptr<DobbyRdkPluginUtils> &utils,
                  const std::string &rootfsPath);

public:
    inline std::string name() const override
    {
        return mName;
    };

    // Override to return the appropriate hints for what we implement
    unsigned hookHints() const override;

    // This test hook implements everything
public:
    bool postInstallation() override;

    bool preCreation() override;

    bool createRuntime() override;

    bool createContainer() override;

#ifdef USE_STARTCONTAINER_HOOK
    bool startContainer() override;
#endif

    bool postStart() override;

    bool postHalt() override;

    bool postStop() override;

public:
    std::vector<std::string> getDependencies() const override;

private:
    const std::string mName;
    std::shared_ptr<rt_dobby_schema> mContainerConfig;
    const std::string mRootfsPath;
    const std::shared_ptr<DobbyRdkPluginUtils> mUtils;
};

#endif // !defined(SuperAwesomePlugin_H)
