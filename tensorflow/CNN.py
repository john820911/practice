import numpy as np
import tensorflow as tf

with tf.variable_scope(
	name_or_scope="conv_1",
	default_name=None,
	values=None,
	initializer=tf.random_uniform_initializer(
		minval=-0.1,
		maxval=0.1,
		seed=None,
		dtype=tf.float32
	),
	regularizer=tf.contrib.layers.l2_regularizer(
		scale=0.1,
		scope="conv_1"
	),
	reuse=False,
	dtype=tf.float32
):
	W_1 = tf.get_variable(
		name="W",
		shape=[ 3, 3, 1, 1 ],
		dtype=tf.float32,
		initializer=tf.random_uniform_initializer(
			minval=-0.1,
			maxval=0.1,
			seed=None,
			dtype=tf.float32
		),
		regularizer=tf.contrib.layers.l2_regularizer(
			scale=0.1,
			scope="conv_1"
		),
		trainable=True,
		collections=None		
	)
	b_1 = tf.get_variable(
		name="b",
		shape=[ 1, 1, 1, 1 ],
		dtype=tf.float32,
		initializer=tf.random_uniform_initializer(
			minval=-0.1,
			maxval=0.1,
			seed=None,
			dtype=tf.float32
		),
		regularizer=tf.contrib.layers.l2_regularizer(
			scale=0.1,
			scope="conv_1"
		),
		trainable=True,
		collections=None,
	)
	print tf.get_collection(tf.GraphKeys.REGULARIZATION_LOSSES)

init_op = tf.global_variables_initializer()

x_1 = tf.placeholder(
	dtype=tf.float32,
	shape=[ None, 3, 3, 1 ],
	name="x_1",
)

z_1 = tf.nn.conv2d(
	input=x_1,
	filter=W_1,
	strides=[ 1, 1, 1, 1 ],
	padding="VALID",
	use_cudnn_on_gpu=True,
	data_format="NHWC",
	name="z_1"
)

session = tf.Session()

session.run(init_op)

feed_dict = {
	x_1: np.arange(9).reshape(-1, 3, 3, 1)
}

fetch_dict = {
	"W_1": W_1,
	"z_1": z_1
}

track_dict = session.run(fetch_dict, feed_dict)

print track_dict["W_1"], track_dict["z_1"]
