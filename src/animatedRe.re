module Animation = {
  type t;
  type endResult = {. "finished": Js.boolean};
  type endCallback = endResult => unit;
};

module type Value = {type t; type rawJsType;};

module CompositeAnimation = {
  type t;
  [@bs.send]
  external _start : (t, Js.undefined(Animation.endCallback)) => unit =
    "start";
  let start = (t, ~callback=?, ()) =>
    _start(t, Js.Undefined.fromOption(callback));
  [@bs.send] external stop : t => unit = "";
  [@bs.send] external reset : t => unit = "";
};

module Easing = {
  type t = float => float;
  [@bs.module "react-native"] [@bs.scope "Easing"] external bounce : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external circle : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external cubic : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external ease : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external exp : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external linear : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external poly : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external quad : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external sin : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external step0 : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external step1 : t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"]
  external back : float => t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"]
  external elastic : float => t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"]
  external in_ : t => t = "in";
  [@bs.module "react-native"] [@bs.scope "Easing"]
  external inOut : t => t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"] external out : t => t = "";
  [@bs.module "react-native"] [@bs.scope "Easing"]
  external bezier : (float, float, float, float) => t = "";
};

module Animations = {
  module Decay = (Val: Value) => {
    type config;
    [@bs.obj]
    external makeConfig :
      (
        ~velocity: Val.rawJsType,
        ~deceleration: float=?,
        ~isInteraction: Js.boolean=?,
        ~useNativeDriver: Js.boolean=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _decay : (Val.t, config) => CompositeAnimation.t = "decay";
    let animate =
        (
          ~value,
          ~velocity,
          ~deceleration=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _decay(
        value,
        makeConfig(
          ~velocity,
          ~deceleration?,
          ~isInteraction=?UtilsRN.optBoolToOptJsBoolean(isInteraction),
          ~useNativeDriver=?UtilsRN.optBoolToOptJsBoolean(useNativeDriver),
          ~onComplete?,
          ~iterations?,
        ),
      );
  };
  module Spring = (Val: Value) => {
    type toValue;
    type config = {
      .
      "toValue": toValue,
      "restDisplacementThreshold": Js.undefined(float),
      "overshootClamping": Js.undefined(Js.boolean),
      "restSpeedThreshold": Js.undefined(float),
      "velocity": Js.undefined(Val.rawJsType),
      "bounciness": Js.undefined(float),
      "speed": Js.undefined(float),
      "tension": Js.undefined(float),
      "friction": Js.undefined(float),
      "stiffness": Js.undefined(float),
      "mass": Js.undefined(float),
      "damping": Js.undefined(float),
      "isInteraction": Js.undefined(Js.boolean),
      "useNativeDriver": Js.undefined(Js.boolean),
      "onComplete": Js.undefined(Animation.endCallback),
      "iterations": Js.undefined(int),
    };
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _spring : (Val.t, config) => CompositeAnimation.t = "spring";
    let animate =
        (
          ~value,
          ~toValue,
          ~restDisplacementThreshold=?,
          ~overshootClamping=?,
          ~restSpeedThreshold=?,
          ~velocity=?,
          ~bounciness=?,
          ~speed=?,
          ~tension=?,
          ~friction=?,
          ~stiffness=?,
          ~mass=?,
          ~damping=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _spring(
        value,
        Js.Undefined.(
          {
            "toValue":
              switch (toValue) {
              | `raw(x) => toValueRaw(x)
              | `animated(x) => toValueAnimated(x)
              },
            "restDisplacementThreshold":
              fromOption(restDisplacementThreshold),
            "overshootClamping": fromOption(overshootClamping),
            "restSpeedThreshold": fromOption(restSpeedThreshold),
            "velocity": fromOption(velocity),
            "bounciness": fromOption(bounciness),
            "speed": fromOption(speed),
            "tension": fromOption(tension),
            "friction": fromOption(friction),
            "stiffness": fromOption(stiffness),
            "mass": fromOption(mass),
            "damping": fromOption(damping),
            "isInteraction": fromOption(isInteraction),
            "useNativeDriver": fromOption(useNativeDriver),
            "onComplete": fromOption(onComplete),
            "iterations": fromOption(iterations),
          }
        ),
      );
  };
  module Timing = (Val: Value) => {
    type toValue;
    type config;
    [@bs.obj]
    external makeConfig :
      (
        ~toValue: toValue,
        ~easing: Easing.t=?,
        ~duration: float=?,
        ~delay: float=?,
        ~isInteraction: Js.boolean=?,
        ~useNativeDriver: Js.boolean=?,
        ~onComplete: Animation.endCallback=?,
        ~iterations: int=?
      ) =>
      config =
      "";
    external toValueRaw : Val.rawJsType => toValue = "%identity";
    external toValueAnimated : Val.t => toValue = "%identity";
    [@bs.module "react-native"] [@bs.scope "Animated"]
    external _timing : (Val.t, config) => CompositeAnimation.t = "timing";
    let animate =
        (
          ~value,
          ~toValue,
          ~easing=?,
          ~duration=?,
          ~delay=?,
          ~isInteraction=?,
          ~useNativeDriver=?,
          ~onComplete=?,
          ~iterations=?,
          (),
        ) =>
      _timing(
        value,
        makeConfig(
          ~toValue=
            switch (toValue) {
            | `raw(x) => toValueRaw(x)
            | `animated(x) => toValueAnimated(x)
            },
          ~easing?,
          ~duration?,
          ~delay?,
          ~isInteraction?,
          ~useNativeDriver?,
          ~onComplete?,
          ~iterations?,
        ),
      );
  };
};

module ValueOperations = (Val: Value) => {
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external add : (Val.t, Val.t) => Val.t = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external divide : (Val.t, Val.t) => Val.t = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external multiply : (Val.t, Val.t) => Val.t = "";
  module Timing = Animations.Timing(Val);
  module Spring = Animations.Spring(Val);
  module Decay = Animations.Decay(Val);
};

module Interpolation = {
  type t;
  type outputRange;
  external outputRangeCreate : 'a => outputRange = "%identity";
  type extrapolate =
    | Extend
    | Clamp
    | Identity;
  let extrapolateString = x =>
    switch (x) {
    | Extend => "extend"
    | Clamp => "clamp"
    | Identity => "identity"
    };
  type config;
  [@bs.obj]
  external makeConfig :
    (
      ~inputRange: array(float),
      ~outputRange: outputRange,
      ~easing: Easing.t=?,
      ~extrapolate: string=?,
      ~extrapolateLeft: string=?,
      ~extrapolateRight: string=?
    ) =>
    config =
    "";
  [@bs.send] external _interpolate : (t, config) => t = "interpolate";
  let interpolate =
      (
        ~value,
        ~inputRange,
        ~outputRange,
        ~easing=?,
        ~extrapolate=?,
        ~extrapolateLeft=?,
        ~extrapolateRight=?,
        (),
      ) =>
    _interpolate(
      value,
      makeConfig(
        ~inputRange=Array.of_list(inputRange),
        ~outputRange=
          switch (outputRange) {
          | `string((x: list(string))) =>
            outputRangeCreate(Array.of_list(x))
          | `float((x: list(float))) => outputRangeCreate(Array.of_list(x))
          },
        ~easing?,
        ~extrapolate=?UtilsRN.option_map(extrapolateString, extrapolate),
        ~extrapolateRight=?
          UtilsRN.option_map(extrapolateString, extrapolateRight),
        ~extrapolateLeft=?
          UtilsRN.option_map(extrapolateString, extrapolateLeft),
      ),
    );
};

module Value = {
  type t;
  type jsValue = {. "value": float};
  type callback = jsValue => unit;
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"]
  external create : float => t = "Value";
  [@bs.send] external setValue : (t, float) => unit = "setValue";
  [@bs.send] external setOffset : (t, float) => unit = "setOffset";
  [@bs.send] external flattenOffset : t => unit = "flattenOffset";
  [@bs.send] external extractOffset : t => unit = "extractOffset";
  [@bs.send] external addListener : (t, callback) => string = "addListener";
  [@bs.send] external removeListener : (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners : t => unit = "removeAllListeners";
  [@bs.send]
  external _resetAnimation : (t, Js.Undefined.t(callback)) => unit =
    "resetAnimation";
  [@bs.send]
  external _stopAnimation : (t, Js.Undefined.t(callback)) => unit =
    "stopAnimation";
  let resetAnimation = (value, ~callback=?, ()) =>
    _resetAnimation(value, Js.Undefined.fromOption(callback));
  let stopAnimation = (value, ~callback=?, ()) =>
    _stopAnimation(value, Js.Undefined.fromOption(callback));
  [@bs.send]
  external _interpolate : (t, Interpolation.config) => Interpolation.t =
    "interpolate";
  let interpolate =
      (
        value,
        ~inputRange,
        ~outputRange,
        ~easing=?,
        ~extrapolate=?,
        ~extrapolateLeft=?,
        ~extrapolateRight=?,
        (),
      ) =>
    _interpolate(
      value,
      Interpolation.makeConfig(
        ~inputRange=Array.of_list(inputRange),
        ~outputRange=
          switch (outputRange) {
          | `string((x: list(string))) =>
            Interpolation.outputRangeCreate(Array.of_list(x))
          | `float((x: list(float))) =>
            Interpolation.outputRangeCreate(Array.of_list(x))
          },
        ~easing?,
        ~extrapolate=?
          UtilsRN.option_map(Interpolation.extrapolateString, extrapolate),
        ~extrapolateLeft=?
          UtilsRN.option_map(
            Interpolation.extrapolateString,
            extrapolateLeft,
          ),
        ~extrapolateRight=?
          UtilsRN.option_map(
            Interpolation.extrapolateString,
            extrapolateRight,
          ),
      ),
    );
  [@bs.send]
  external animate : (t, Animation.t, Animation.endCallback) => unit =
    "animate";
  [@bs.send] external stopTracking : t => unit = "stopTracking";
  [@bs.send] external track : t => unit = "track";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external modulo : (t, float) => t = "";
  [@bs.module "react-native"] [@bs.scope "Animated"]
  external diffClamp : (t, float, float) => t = "";
  external fromInterpolated : Interpolation.t => t = "%identity";
  type value = t;
  include
    ValueOperations(
      {
        type t = value;
        type rawJsType = float;
      },
    );
};

module ValueXY = {
  type t;
  type jsValue = {
    .
    "x": float,
    "y": float,
  };
  type callback = jsValue => unit;
  type translateTransform = {
    .
    "translateX": Value.t,
    "translateY": Value.t,
  };
  type layout = {
    .
    "left": Value.t,
    "top": Value.t,
  };
  [@bs.new] [@bs.scope "Animated"] [@bs.module "react-native"]
  external _create : jsValue => t = "ValueXY";
  let create = (~x, ~y) => _create({"x": x, "y": y});
  [@bs.send] external _setValue : (t, jsValue) => unit = "setValue";
  let setValue = (t, ~x, ~y) => _setValue(t, {"x": x, "y": y});
  [@bs.send] external _setOffset : (t, jsValue) => unit = "setOffset";
  let setOffset = (t, ~x, ~y) => _setOffset(t, {"x": x, "y": y});
  [@bs.send] external flattenOffset : t => unit = "flattenOffset";
  [@bs.send] external extractOffset : t => unit = "extractOffset";
  [@bs.send]
  external resetAnimation : (t, option(callback)) => unit = "resetAnimation";
  [@bs.send]
  external stopAnimation : (t, option(callback)) => unit = "stopAnimation";
  [@bs.send] external addListener : (t, callback) => string = "addListener";
  [@bs.send] external removeListener : (t, string) => unit = "removeListener";
  [@bs.send] external removeAllListeners : t => unit = "removeAllListeners";
  [@bs.send] external getLayout : t => layout = "getLayout";
  [@bs.send]
  external getTranslateTransform : t => translateTransform =
    "getTranslateTransform";
  [@bs.get] external getX : t => Value.t = "x";
  [@bs.get] external getY : t => Value.t = "y";
  type value = t;
  include
    ValueOperations(
      {
        type t = value;
        type rawJsType = jsValue;
      },
    );
};

[@bs.module "react-native"] [@bs.scope "Animated"]
external delay : float => CompositeAnimation.t = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external sequence : array(CompositeAnimation.t) => CompositeAnimation.t = "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external parallel :
  (array(CompositeAnimation.t), {. "stopTogether": Js.boolean}) =>
  CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external stagger :
  (float, array(CompositeAnimation.t)) => CompositeAnimation.t =
  "";

[@bs.module "react-native"] [@bs.scope "Animated"]
external _loop :
  (CompositeAnimation.t, {. "iterations": int}) => CompositeAnimation.t =
  "loop";

type animatedEvent;

[@bs.module "react-native"] [@bs.scope "Animated"]
external event : (array('a), 'b) => animatedEvent = "";

let loop = (~iterations=(-1), ~animation, ()) =>
  _loop(animation, {"iterations": iterations});

[@bs.module "react-native"] [@bs.scope "Animated"]
external createAnimatedComponent :
  ReasonReact.reactClass => ReasonReact.reactClass =
  "";

module Timing = Value.Timing;

module TimingXY = ValueXY.Timing;

module Spring = Value.Spring;

module SpringXY = ValueXY.Spring;

module Decay = Value.Decay;

module DecayXY = ValueXY.Decay;