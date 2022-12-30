; 脚本由 Inno Setup 脚本向导 生成！
; 有关创建 Inno Setup 脚本文件的详细资料请查阅帮助文档！
#define MyCompanyName "Cappo"
#define MyAppName "Cappo Of Cappo"
#define MyAppVersion "1.0.1"
#define MyAppPublisher "Dvrsoft Systems, Inc."
#define MyAppURL ""
#define MyAppExeName "VCMS.exe"
#define MyTempOutPutName "VCMS_P2P"
#define MyDBName "VCMS.db"

#define MyAppSrcFolder     "Release"
#define MyAppId   "{DE8F044D-4CAD-433F-959B-FF9C7C97669F}"
#define MyBuildTime        GetDateTimeString('yyyy_mm_dd', '', '');
[Setup]
; 注: AppId的值为单独标识该应用程序。
; 不要为其他安装程序使用相同的AppId值。
; (生成新的GUID，点击 工具|在IDE中生成GUID。)
AppId={{#MyAppId}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
;AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyCompanyName}\{#MyAppName}
DefaultGroupName={#MyCompanyName}\{#MyAppName}
OutputDir=.\Output\V{#MyAppVersion}
OutputBaseFilename={#MyTempOutPutName}_{#MyAppVersion}_{#MyBuildTime}
Compression=lzma
SolidCompression=yes
WizardImageFile=.\image\left.bmp
UsePreviousAppDir=yes
[Languages]
Name: "english"; MessagesFile: "compiler:\Languages\English.islu"        

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"
Name: "quicklaunchicon"; Description: "{cm:CreateQuickLaunchIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: ".\{#MyAppSrcFolder}\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: ".\{#MyAppSrcFolder}\*"; DestDir: "{app}"; Excludes: "*.pdb"; Flags: ignoreversion recursesubdirs createallsubdirs
; 注意: 不要在任何共享系统文件上使用“Flags: ignoreversion”
  ; Add the ISSkin DLL used for skinning Inno Setup installations.
Source: compiler:ISSkin.dll; DestDir: {app}; Flags: dontcopy
; Add the Visual Style resource contains resources used for skinning,
; you can also use Microsoft Visual Styles (*.msstyles) resources.
Source: compiler:IsSkins\Office2007.cjstyles; DestDir: {tmp}; Flags: dontcopy

[UninstallDelete]
;Type: files; Name: "{app}\*.*"
Type: filesandordirs; Name: "{app}\*."
Type: filesandordirs; Name: "{userappdata}\{#MyCompanyName}\{#MyAppName}\*.ini"
Type: filesandordirs; Name: "{userappdata}\{#MyCompanyName}\{#MyAppName}\*.db"


[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"; IconFilename: "{app}\Uninstall.ico"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon
Name: "{userappdata}\Microsoft\Internet Explorer\Quick Launch\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: quicklaunchicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "{cm:LaunchProgram,{#StringChange(MyAppName, '&', '&&')}}"; Flags: nowait postinstall skipifsilent
Filename: {app}\vcredist_x86.exe; Parameters: /q; Flags: skipifdoesntexist; StatusMsg: "Installing Microsoft Visual C++ Runtime ..."; Check: NeedInstallMSVCRuntime;

[Code]
// Importing LoadSkin API from ISSkin.DLL
procedure LoadSkin(lpszPath: AnsiString; lpszIniFileName: AnsiString);
external 'LoadSkin@files:isskin.dll stdcall';

// Importing UnloadSkin API from ISSkin.DLL
procedure UnloadSkin();
external 'UnloadSkin@files:isskin.dll stdcall';

// Importing ShowWindow Windows API from User32.DLL
function ShowWindow(hWnd: Integer; uType: Integer): Integer;
external 'ShowWindow@user32.dll stdcall';

procedure CurUninstallStepChanged(CurUninstallStep:TUninstallStep);
var DeleteProfile: string;
begin                    
if  CurUninstallStep = usUninstall then
if  MsgBox('Whether to delete the user profiles ?',mbConfirmation,MB_YESNO)=IDYES 
then DeleteProfile := ExpandConstant('{userappdata}\{#MyCompanyName}\{#MyAppName}');
DelTree(DeleteProfile, True, True, True);
end;

function IsAppRuning(): Boolean;
var
HasRun:Boolean;
strFile :string;
strNewFile :string;
posIndex :Integer;
begin
Result:= false;
strFile := ExpandConstant('{userappdata}\{#MyCompanyName}\{#MyAppName}\{#MyAppName}');
strFile := strFile + '.db';
HasRun := FileExists(strFile);
if HasRun = true then
begin
posIndex := Pos('.', strFile);
strNewFile := Copy(strFile, 0, posIndex-1);
strNewFile := strNewFile + '1.db';
FileCopy(strFile, strNewFile, false);
HasRun := DeleteFile(strFile);
if HasRun = false then
begin
Result := true;
end else
begin
strFile := strNewFile;
strNewFile := ExpandConstant('{userappdata}\{#MyCompanyName}\{#MyAppName}\{#MyDBName}');
RenameFile(strFile, strNewFile);
end
end
end;


function AppUinstallFinish():Boolean;
 var
 I: Integer;
begin
Result:= true;
  for I := 0 to 10 do
  begin
    if IsAppRuning() = true then
    begin
      Sleep(500);
      I := I +1;
    end else
    begin
      Result:= false;
      break;
    end
  end
end;


function SetAppRunMsg(msg:string):Boolean;
begin
Result:= false;
if IsAppRuning()<>false then
begin
Result:= true;
MsgBox(msg, mbInformation, MB_OK);
end 
end;

// 0 ==,-1 low ,1 high
function AppVersionCampare():integer;
var
  bool  : Boolean;
  Sapp,ResultStr : string;

begin
  Result:= -1;
  Sapp := '{#MyAppId}'; 
  Sapp := Sapp + '_is1';
  bool := RegQueryStringValue(HKEY_LOCAL_MACHINE,'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\'+Sapp,'DisplayVersion',ResultStr);
  if bool then
  begin 
 Result := CompareStr('{#MyAppVersion}',ResultStr);
  end
end;   

function IsOldVersionexist():Boolean;
var
  Names: TArrayOfString;
  I: Integer;
  S: string;
  bool  : Boolean;
  ResultStr : string;
  ResultCode: Integer;
 
begin
  Result:= true;
  S := '{#MyAppId}'; 
  S := S + '_is1';
  if RegGetSubkeyNames(HKEY_LOCAL_MACHINE,'Software\{#MyCompanyName}',Names) then
  begin
 
    for I := 0 to GetArrayLength(Names)-1 do
     begin
     
     if '{#MyAppName}' = Names[I] then
      begin
      bool := RegQueryStringValue(HKEY_LOCAL_MACHINE,'SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\'+S,'UninstallString',ResultStr);
      if bool then
        begin
          if MsgBox('Setup has detected that the computer has been installed on the {#MyAppName} client.' #13#13 'Whether you want to uninstall {#MyAppName} client?',  mbConfirmation, MB_YESNO) = IDYES then
            begin
              Exec(RemoveQuotes(ResultStr), '', '', SW_SHOW, ewWaitUntilTerminated, ResultCode);
              if AppUinstallFinish() = true then
              begin
              Result := false;
              end else
              begin
              Result := true;
              end
            end else
            begin
             Result := false;
            end
        end; 
        break;
      end else
      begin
      if SetAppRunMsg('Setup has detected that there is another application is already running.') = false then
      begin
       Result := true;
       end else
       begin
       Result := false;
       break;
       end
      end
     end;
  end else
  begin
    // 添加处理失败的代码
  end;
end;

procedure URLLabelOnClick(Sender: TObject);
var
ErrorCode: Integer;
begin
ShellExec('open', '{#MyAppURL}', '', '', SW_SHOW, ewNoWait, ErrorCode)
end;

procedure InitializeWizard();
var
  URLLabel: TNewStaticText;
begin
  URLLabel := TNewStaticText.Create(WizardForm);
  URLLabel.Top := WizardForm.CancelButton.Top+5;
  URLLabel.Left := WizardForm.ClientWidth - WizardForm.CancelButton.Left - WizardForm.CancelButton.Width;
  URLLabel.Caption := '{#MyAppPublisher}';
  URLLabel.Font.Color := clBlue;
  URLLabel.Font.Name := '宋体';
  URLLabel.Font.Height := ScaleY(-13);
  URLLabel.Parent := WizardForm;
  if '{#MyAppURL}' = '' then 
  else begin
  URLLabel.Cursor := crHand;
  URLLabel.OnClick := @URLLabelOnClick;
  URLLabel.Hint := '点击访问网站';
  URLLabel.ShowHint := True;
  end;
end;

procedure DeinitializeSetup();
begin
	// Hide Window before unloading skin so user does not get
	// a glimse of an unskinned window before it is closed.
	ShowWindow(StrToInt(ExpandConstant('{wizardhwnd}')), 0);
	UnloadSkin();
end;

//当用户单击cancel的时候，删除掉拷贝到系统的文件夹
procedure CancelButtonClick(CurPageID: Integer; var Cancel, Confirm: Boolean);
begin
end ;

function NeedInstallMSVCRuntime(): Boolean;
var
strMsvcp140:string;
strVcruntime140:string;
begin
	Result := false;
	strMsvcp140 := ExpandConstant('{sys}\msvcp140');
	strMsvcp140 := strMsvcp140 + '.dll';
	
	strVcruntime140 := ExpandConstant('{sys}\vcruntime140');
	strVcruntime140 := strVcruntime140 + '.dll';
	
  	if FileExists(strMsvcp140) = false then
	begin
		Result := true;
	end;
	
	if FileExists(strVcruntime140) = false then
	begin
		Result := true;
	end;
end;

function InitializeSetup(): Boolean;
var s: string;
begin
	ExtractTemporaryFile('Office2007.cjstyles');
	LoadSkin(AnsiString(ExpandConstant('{tmp}\Office2007.cjstyles')), 'NormalBlack.ini');
	Result := false;
 
  if IsOldVersionexist() = true then 
  begin
  Result := true;
  end;
  
end;

function InitializeUninstall(): Boolean;
begin
    Result := true;
    if SetAppRunMsg('Program is running, please exit and then uninstall') = true then
    begin
       Result := false;
   
     end
end;

[Registry]
Root: HKLM; Subkey: "Software\{#MyCompanyName}\{#MyAppName}"; ValueType: string; ValueName:"{#MyAppName}"; ValueData:"{app}\{#MyAppExeName}"; Flags: uninsdeletekey

  
