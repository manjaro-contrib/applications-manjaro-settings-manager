/*
 *  This file is part of Manjaro Settings Manager.
 *
 *  Roman Gilg <romangg@manjaro.org>
 *
 *  Manjaro Settings Manager is free software: you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Manjaro Settings Manager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Manjaro Settings Manager.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "MddAuthHelper.h"

#include <QtCore/QFile>
#include <QtCore/QProcess>
#include <QtCore/QSet>
#include <QFileInfo>
#include <QSettings>
#include <QDir>
#include <QtDBus/QDBusInterface>

ActionReply MddAuthHelper::save(QVariantMap const &args) {
  QString const configPath = "/etc/mdd.conf";

  auto advanced = args["advanced"].toBool();

  // If value is false and file does not exist: do nothing
  if (!advanced && !QFileInfo::exists(configPath)) {
    return ActionReply::SuccessReply();
  }

  // Ensure directory exists
//   QDir().mkpath(QFileInfo(configPath).absolutePath());

  QSettings settings(configPath, QSettings::IniFormat);
  settings.beginGroup("telemetry");
  settings.setValue("advanced", advanced);
  settings.endGroup();

  // Force immediate write to disk
  settings.sync();

  return ActionReply::SuccessReply();
}

KAUTH_HELPER_MAIN("org.manjaro.msm.mdd", MddAuthHelper)
#include "moc_MddAuthHelper.cpp"
