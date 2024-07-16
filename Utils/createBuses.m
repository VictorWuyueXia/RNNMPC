% %% BusActors
% BusActors = Simulink.Bus;
% BusActors.Description = '';
% BusActors.DataScope = 'Auto';
% BusActors.HeaderFile = '';
% BusActors.Alignment = -1;
% 
% saveVarsTmp{1} = Simulink.BusElement;
% saveVarsTmp{1}.Name = 'NumActors';
% saveVarsTmp{1}.Complexity = 'real';
% saveVarsTmp{1}.Dimensions = [1 1];
% saveVarsTmp{1}.DataType = 'double';
% saveVarsTmp{1}.Min = [];
% saveVarsTmp{1}.Max = [];
% saveVarsTmp{1}.DimensionsMode = 'Fixed';
% saveVarsTmp{1}.SamplingMode = 'Sample based';
% saveVarsTmp{1}.DocUnits = '';
% saveVarsTmp{1}.Description = '';
% 
% saveVarsTmp{1}(2, 1) = Simulink.BusElement;
% saveVarsTmp{1}(2, 1).Name = 'Time';
% saveVarsTmp{1}(2, 1).Complexity = 'real';
% saveVarsTmp{1}(2, 1).Dimensions = [1 1];
% saveVarsTmp{1}(2, 1).DataType = 'double';
% saveVarsTmp{1}(2, 1).Min = [];
% saveVarsTmp{1}(2, 1).Max = [];
% saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(2, 1).DocUnits = '';
% saveVarsTmp{1}(2, 1).Description = '';
% 
% saveVarsTmp{1}(3, 1) = Simulink.BusElement;
% saveVarsTmp{1}(3, 1).Name = 'Actors';
% saveVarsTmp{1}(3, 1).Complexity = 'real';
% saveVarsTmp{1}(3, 1).Dimensions = [1 1];
% saveVarsTmp{1}(3, 1).DataType = 'Bus: busActorsActors';
% saveVarsTmp{1}(3, 1).Min = [];
% saveVarsTmp{1}(3, 1).Max = [];
% saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(3, 1).DocUnits = '';
% saveVarsTmp{1}(3, 1).Description = '';
% BusActors.Elements = saveVarsTmp{1};
% clear saveVarsTmp;
% 
% %% BusActorsActors
% BusActorsActors = Simulink.Bus;
% BusActorsActors.Description = '';
% BusActorsActors.DataScope = 'Auto';
% BusActorsActors.HeaderFile = '';
% BusActorsActors.Alignment = -1;
% 
% saveVarsTmp{1} = Simulink.BusElement;
% saveVarsTmp{1}.Name = 'ActorID';
% saveVarsTmp{1}.Complexity = 'real';
% saveVarsTmp{1}.Dimensions = [1 1];
% saveVarsTmp{1}.DataType = 'double';
% saveVarsTmp{1}.Min = [];
% saveVarsTmp{1}.Max = [];
% saveVarsTmp{1}.DimensionsMode = 'Fixed';
% saveVarsTmp{1}.SamplingMode = 'Sample based';
% saveVarsTmp{1}.DocUnits = '';
% saveVarsTmp{1}.Description = '';
% 
% saveVarsTmp{1}(2, 1) = Simulink.BusElement;
% saveVarsTmp{1}(2, 1).Name = 'Position';
% saveVarsTmp{1}(2, 1).Complexity = 'real';
% saveVarsTmp{1}(2, 1).Dimensions = [1 3];
% saveVarsTmp{1}(2, 1).DataType = 'double';
% saveVarsTmp{1}(2, 1).Min = [];
% saveVarsTmp{1}(2, 1).Max = [];
% saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(2, 1).DocUnits = '';
% saveVarsTmp{1}(2, 1).Description = '';
% 
% saveVarsTmp{1}(3, 1) = Simulink.BusElement;
% saveVarsTmp{1}(3, 1).Name = 'Velocity';
% saveVarsTmp{1}(3, 1).Complexity = 'real';
% saveVarsTmp{1}(3, 1).Dimensions = [1 3];
% saveVarsTmp{1}(3, 1).DataType = 'double';
% saveVarsTmp{1}(3, 1).Min = [];
% saveVarsTmp{1}(3, 1).Max = [];
% saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(3, 1).DocUnits = '';
% saveVarsTmp{1}(3, 1).Description = '';
% 
% saveVarsTmp{1}(4, 1) = Simulink.BusElement;
% saveVarsTmp{1}(4, 1).Name = 'Roll';
% saveVarsTmp{1}(4, 1).Complexity = 'real';
% saveVarsTmp{1}(4, 1).Dimensions = [1 1];
% saveVarsTmp{1}(4, 1).DataType = 'double';
% saveVarsTmp{1}(4, 1).Min = [];
% saveVarsTmp{1}(4, 1).Max = [];
% saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(4, 1).DocUnits = '';
% saveVarsTmp{1}(4, 1).Description = '';
% 
% saveVarsTmp{1}(5, 1) = Simulink.BusElement;
% saveVarsTmp{1}(5, 1).Name = 'Pitch';
% saveVarsTmp{1}(5, 1).Complexity = 'real';
% saveVarsTmp{1}(5, 1).Dimensions = [1 1];
% saveVarsTmp{1}(5, 1).DataType = 'double';
% saveVarsTmp{1}(5, 1).Min = [];
% saveVarsTmp{1}(5, 1).Max = [];
% saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(5, 1).DocUnits = '';
% saveVarsTmp{1}(5, 1).Description = '';
% 
% saveVarsTmp{1}(7, 1) = Simulink.BusElement;
% saveVarsTmp{1}(7, 1).Name = 'Yaw';
% saveVarsTmp{1}(7, 1).Complexity = 'real';
% saveVarsTmp{1}(7, 1).Dimensions = [1 1];
% saveVarsTmp{1}(7, 1).DataType = 'double';
% saveVarsTmp{1}(7, 1).Min = [];
% saveVarsTmp{1}(7, 1).Max = [];
% saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(7, 1).DocUnits = '';
% saveVarsTmp{1}(7, 1).Description = '';
% 
% saveVarsTmp{1}(7, 1) = Simulink.BusElement;
% saveVarsTmp{1}(7, 1).Name = 'AngularVelocity';
% saveVarsTmp{1}(7, 1).Complexity = 'real';
% saveVarsTmp{1}(7, 1).Dimensions = [1 3];
% saveVarsTmp{1}(7, 1).DataType = 'double';
% saveVarsTmp{1}(7, 1).Min = [];
% saveVarsTmp{1}(7, 1).Max = [];
% saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
% saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
% saveVarsTmp{1}(7, 1).DocUnits = '';
% saveVarsTmp{1}(7, 1).Description = '';
% 
% BusActorsActors.Elements = saveVarsTmp{1};
% clear saveVarsTmp;

%% Ego Vehicle State
BusEgoVehicleState = Simulink.Bus;
BusEgoVehicleState.Description = '';
BusEgoVehicleState.DataScope = 'Auto';
BusEgoVehicleState.HeaderFile = '';
BusEgoVehicleState.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'ActorID';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = [1 1];
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = '';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'Position';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = [1 3];
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = 'm';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'Velocity';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = [1 3];
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = 'm/s';
saveVarsTmp{1}(3, 1).Description = '';

saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'Acceleration';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = [1 3];
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).DocUnits = 'm/s^2';
saveVarsTmp{1}(4, 1).Description = '';

saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'Orientation';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = [1 3];
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Min = [];
saveVarsTmp{1}(5, 1).Max = [];
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).DocUnits = 'deg';
saveVarsTmp{1}(5, 1).Description = '';

saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'AngularVelocity';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = [1 3];
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Min = [];
saveVarsTmp{1}(6, 1).Max = [];
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).DocUnits = 'deg/s';
saveVarsTmp{1}(6, 1).Description = '';

saveVarsTmp{1}(7, 1) = Simulink.BusElement;
saveVarsTmp{1}(7, 1).Name = 'AngularAcceleration';
saveVarsTmp{1}(7, 1).Complexity = 'real';
saveVarsTmp{1}(7, 1).Dimensions = [1 3];
saveVarsTmp{1}(7, 1).DataType = 'double';
saveVarsTmp{1}(7, 1).Min = [];
saveVarsTmp{1}(7, 1).Max = [];
saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(7, 1).DocUnits = 'deg/s^2';
saveVarsTmp{1}(7, 1).Description = '';

BusEgoVehicleState.Elements = saveVarsTmp{1};
clear saveVarsTmp;


%% Ego Vehicle Pose
BusEgoVehiclePose = Simulink.Bus;
BusEgoVehiclePose.Description = '';
BusEgoVehiclePose.DataScope = 'Auto';
BusEgoVehiclePose.HeaderFile = '';
BusEgoVehiclePose.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'ActorID';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = [1 1];
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = '';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'Position';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = [1 3];
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = 'm';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'Velocity';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = [1 3];
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = 'm/s';
saveVarsTmp{1}(3, 1).Description = '';

saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'Roll';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = [1 1];
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).DocUnits = 'deg';
saveVarsTmp{1}(4, 1).Description = '';

saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'Pitch';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = [1 1];
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Min = [];
saveVarsTmp{1}(5, 1).Max = [];
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).DocUnits = 'deg';
saveVarsTmp{1}(5, 1).Description = '';

saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'Yaw';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = [1 1];
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Min = [];
saveVarsTmp{1}(6, 1).Max = [];
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).DocUnits = 'deg';
saveVarsTmp{1}(6, 1).Description = '';

saveVarsTmp{1}(7, 1) = Simulink.BusElement;
saveVarsTmp{1}(7, 1).Name = 'AngularVelocity';
saveVarsTmp{1}(7, 1).Complexity = 'real';
saveVarsTmp{1}(7, 1).Dimensions = [1 3];
saveVarsTmp{1}(7, 1).DataType = 'double';
saveVarsTmp{1}(7, 1).Min = [];
saveVarsTmp{1}(7, 1).Max = [];
saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(7, 1).DocUnits = 'deg/s';
saveVarsTmp{1}(7, 1).Description = '';

BusEgoVehiclePose.Elements = saveVarsTmp{1};
clear saveVarsTmp;

%% Vehicle Kinematics
BusVehicleKinematics = Simulink.Bus;
BusVehicleKinematics.Description = '';
BusVehicleKinematics.DataScope = 'Auto';
BusVehicleKinematics.HeaderFile = '';
BusVehicleKinematics.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'WheelBase';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = 'm';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'VehicleSpeedRange';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 2;
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = 'm/s';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'MaxSteeringAngle';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = 'rad';
saveVarsTmp{1}(3, 1).Description = '';

BusVehicleKinematics.Elements = saveVarsTmp{1};
clear saveVarsTmp;
%% Obj Func Term Weights
BusWeights = Simulink.Bus;
BusWeights.Description = '';
BusWeights.DataScope = 'Auto';
BusWeights.HeaderFile = '';
BusWeights.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'input';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 2;
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = '';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'progress';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = '';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'laneKeeping';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 2;
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = '';
saveVarsTmp{1}(3, 1).Description = '';

saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'obsAvoid';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).DocUnits = '';
saveVarsTmp{1}(4, 1).Description = '';

saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'RL';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = 1;
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Min = [];
saveVarsTmp{1}(5, 1).Max = [];
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).DocUnits = '';
saveVarsTmp{1}(5, 1).Description = '';

saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'softConstraintPenalty';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = 1;
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Min = [];
saveVarsTmp{1}(6, 1).Max = [];
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).DocUnits = '';
saveVarsTmp{1}(6, 1).Description = '';

BusWeights.Elements = saveVarsTmp{1};
clear saveVarsTmp;

%% Limits
BusLimits = Simulink.Bus;
BusLimits.Description = '';
BusLimits.DataScope = 'Auto';
BusLimits.HeaderFile = '';
BusLimits.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'speedMAX';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = 'm/s';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'reverseMAX';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = 'm/s';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'accMAX';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = 1;
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = 'm/s^2';
saveVarsTmp{1}(3, 1).Description = '';

saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'jerkMAX';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DataType = 'double';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).DocUnits = 'm/s^3';
saveVarsTmp{1}(4, 1).Description = '';

saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'brakeMAX';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = 1;
saveVarsTmp{1}(5, 1).DataType = 'double';
saveVarsTmp{1}(5, 1).Min = [];
saveVarsTmp{1}(5, 1).Max = [];
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).DocUnits = 'm/s^2';
saveVarsTmp{1}(5, 1).Description = '';

saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'turnAngleMAX';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = 1;
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Min = [];
saveVarsTmp{1}(6, 1).Max = [];
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).DocUnits = 'deg';
saveVarsTmp{1}(6, 1).Description = '';

saveVarsTmp{1}(7, 1) = Simulink.BusElement;
saveVarsTmp{1}(7, 1).Name = 'turnAngleRateMAX';
saveVarsTmp{1}(7, 1).Complexity = 'real';
saveVarsTmp{1}(7, 1).Dimensions = 1;
saveVarsTmp{1}(7, 1).DataType = 'double';
saveVarsTmp{1}(7, 1).Min = [];
saveVarsTmp{1}(7, 1).Max = [];
saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(7, 1).DocUnits = 'deg/s';
saveVarsTmp{1}(7, 1).Description = '';

BusLimits.Elements = saveVarsTmp{1};
clear saveVarsTmp;

%% Params
BusParams = Simulink.Bus;
BusParams.Description = '';
BusParams.DataScope = 'Auto';
BusParams.HeaderFile = '';
BusParams.Alignment = -1;

saveVarsTmp{1} = Simulink.BusElement;
saveVarsTmp{1}.Name = 'Ts';
saveVarsTmp{1}.Complexity = 'real';
saveVarsTmp{1}.Dimensions = 1;
saveVarsTmp{1}.DataType = 'double';
saveVarsTmp{1}.Min = [];
saveVarsTmp{1}.Max = [];
saveVarsTmp{1}.DimensionsMode = 'Fixed';
saveVarsTmp{1}.SamplingMode = 'Sample based';
saveVarsTmp{1}.DocUnits = 's';
saveVarsTmp{1}.Description = '';

saveVarsTmp{1}(2, 1) = Simulink.BusElement;
saveVarsTmp{1}(2, 1).Name = 'L';
saveVarsTmp{1}(2, 1).Complexity = 'real';
saveVarsTmp{1}(2, 1).Dimensions = 1;
saveVarsTmp{1}(2, 1).DataType = 'double';
saveVarsTmp{1}(2, 1).Min = [];
saveVarsTmp{1}(2, 1).Max = [];
saveVarsTmp{1}(2, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(2, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(2, 1).DocUnits = 'm';
saveVarsTmp{1}(2, 1).Description = '';

saveVarsTmp{1}(3, 1) = Simulink.BusElement;
saveVarsTmp{1}(3, 1).Name = 'waypoints_relative';
saveVarsTmp{1}(3, 1).Complexity = 'real';
saveVarsTmp{1}(3, 1).Dimensions = [1 2];
saveVarsTmp{1}(3, 1).DataType = 'double';
saveVarsTmp{1}(3, 1).Min = [];
saveVarsTmp{1}(3, 1).Max = [];
saveVarsTmp{1}(3, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(3, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(3, 1).DocUnits = 'm';
saveVarsTmp{1}(3, 1).Description = '';

saveVarsTmp{1}(4, 1) = Simulink.BusElement;
saveVarsTmp{1}(4, 1).Name = 'costFuncWeights';
saveVarsTmp{1}(4, 1).Complexity = 'real';
saveVarsTmp{1}(4, 1).Dimensions = 1;
saveVarsTmp{1}(4, 1).DataType = 'Bus: BusWeights';
saveVarsTmp{1}(4, 1).Min = [];
saveVarsTmp{1}(4, 1).Max = [];
saveVarsTmp{1}(4, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(4, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(4, 1).DocUnits = '';
saveVarsTmp{1}(4, 1).Description = '';

saveVarsTmp{1}(5, 1) = Simulink.BusElement;
saveVarsTmp{1}(5, 1).Name = 'EgoCar1_params';
saveVarsTmp{1}(5, 1).Complexity = 'real';
saveVarsTmp{1}(5, 1).Dimensions = 1;
saveVarsTmp{1}(5, 1).DataType = 'Bus: BusLimits';
saveVarsTmp{1}(5, 1).Min = [];
saveVarsTmp{1}(5, 1).Max = [];
saveVarsTmp{1}(5, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(5, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(5, 1).DocUnits = '';
saveVarsTmp{1}(5, 1).Description = '';

saveVarsTmp{1}(6, 1) = Simulink.BusElement;
saveVarsTmp{1}(6, 1).Name = 'NumLaneBoundaries';
saveVarsTmp{1}(6, 1).Complexity = 'real';
saveVarsTmp{1}(6, 1).Dimensions = 1;
saveVarsTmp{1}(6, 1).DataType = 'double';
saveVarsTmp{1}(6, 1).Min = [];
saveVarsTmp{1}(6, 1).Max = [];
saveVarsTmp{1}(6, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(6, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(6, 1).DocUnits = '';
saveVarsTmp{1}(6, 1).Description = '';

saveVarsTmp{1}(7, 1) = Simulink.BusElement;
saveVarsTmp{1}(7, 1).Name = 'CurrentLaneVector';
saveVarsTmp{1}(7, 1).Complexity = 'real';
saveVarsTmp{1}(7, 1).Dimensions = [6 2];
saveVarsTmp{1}(7, 1).DataType = 'double';
saveVarsTmp{1}(7, 1).Min = [];
saveVarsTmp{1}(7, 1).Max = [];
saveVarsTmp{1}(7, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(7, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(7, 1).DocUnits = '';
saveVarsTmp{1}(7, 1).Description = '';

saveVarsTmp{1}(8, 1) = Simulink.BusElement;
saveVarsTmp{1}(8, 1).Name = 'Plant';
saveVarsTmp{1}(8, 1).Complexity = 'real';
saveVarsTmp{1}(8, 1).Dimensions = 1;
saveVarsTmp{1}(8, 1).DataType = 'Bus: BusVehicleKinematics';
saveVarsTmp{1}(8, 1).Min = [];
saveVarsTmp{1}(8, 1).Max = [];
saveVarsTmp{1}(8, 1).DimensionsMode = 'Fixed';
saveVarsTmp{1}(8, 1).SamplingMode = 'Sample based';
saveVarsTmp{1}(8, 1).DocUnits = '';
saveVarsTmp{1}(8, 1).Description = '';

BusParams.Elements = saveVarsTmp{1};
clear saveVarsTmp;