import numpy as np
import tensorflow as tf

def layer(input_size, output_size):
	W = tf.get_variable(
		name="W",
		shape=(input_size, output_size),
		dtype=tf.float32,
		initializer=tf.random_normal_initializer(
			mean=0.0,
			stddev=0.1,
			dtype=tf.float32
		),
		regularizer=None,
		trainable=True,
		collections=None
	)
	b = tf.get_variable(
		name="b",
		shape=(output_size, ),
		dtype=tf.float32,
		initializer=tf.random_uniform_initializer(
			minval=-0.1,
			maxval=0.1,
			dtype=tf.float32
		),
		regularizer=None,
		trainable=True,
		collections=None
	)
	return W, b

class DNN:
	def __init__(self, input_size, output_size):
		self.input_size = input_size
		self.output_size = output_size
		with tf.variable_scope(
			name_or_scope="scope_1",
			default_name=None,
			values=None,
			dtype=tf.float32,
			initializer=None,
			regularizer=None,
			reuse=False
		) as scope_1:
			self.W_1, self.b_1 = layer(self.input_size, self.output_size)
	def get_model(self):
		x = tf.placeholder(
			dtype=tf.float32,
			shape=(None, self.input_size),
			name="x"
		)
		y = tf.placeholder(
			dtype=tf.float32,
			shape=(None, self.output_size),
			name="y"
		)
		a_1 = tf.add(tf.matmul(x, self.W_1), self.b_1)
		tf.summary.histogram(
			name="a_1",
			values=a_1
		)
		loss = tf.nn.softmax_cross_entropy_with_logits(
			logits=a_1,
			labels=y,
			dim=-1
		)
		return x, y, a_1, loss

def train():
	model = DNN(100, 10)
	x, y, a_1, loss = model.get_model()
	global_step = tf.contrib.framework.get_or_create_global_step()
	decayed_learning_rate = tf.train.exponential_decay(
		learning_rate=0.01,
		global_step=global_step,
		decay_steps=10,
		decay_rate=0.99,
		staircase=True,
		name="decayed_learning_rate"
	)
	optimizer = tf.train.GradientDescentOptimizer(
		learning_rate=decayed_learning_rate,
		use_locking=False,
		name="optimizer"
	)
	trainable_var_list = tf.get_collection(
		key=tf.GraphKeys.TRAINABLE_VARIABLES,
		scope=None
	)	
	grads_and_vars = optimizer.compute_gradients(
		loss=loss,
		var_list=trainable_var_list
	)
	gradients, variables = zip(*grads_and_vars)
	gradients, _ = tf.clip_by_global_norm(
		t_list=gradients,
		clip_norm=0.9
	)
	optimizer_op = optimizer.apply_gradients(
		grads_and_vars=zip(gradients, variables),
		global_step=global_step,
		name="optimizer_op"
	)
	ema = tf.train.ExponentialMovingAverage(
		decay=0.9,
		num_updates=10
	)
	mover_op = ema.apply(
		var_list=trainable_var_list
	)
	with tf.control_dependencies([optimizer_op]):
		train_op = tf.group(mover_op)
	summary_op = tf.summary.merge_all()
	trainable_shadow_var_list = [ ema.average(var) for var in trainable_var_list ]
	global_var_list = tf.get_collection(
		key=tf.GraphKeys.GLOBAL_VARIABLES,
		scope=None
	)
	initializer_op = tf.variables_initializer(
		var_list=global_var_list,
		name="initializer_op"
	)
	fetch_dict = {
		"x": x,
		"y": y,
		"a_1": a_1,
		"loss": loss,
		"global_step": global_step,
		"decayed_learning_rate": decayed_learning_rate,
		"gradients": gradients,
		"trainable_var_list": trainable_var_list,
		"trainable_shadow_var_list": trainable_shadow_var_list,
		"global_var_list": global_var_list,
		"summary_op": summary_op
	}
	feed_dict = {
		x: 2 * np.random.rand(1, 100) - 1,
		y: np.eye(10)[[4]]
	}
	session = tf.Session()
	session.run(initializer_op)
	track_dict = session.run(fetch_dict, feed_dict)
	saver = tf.train.Saver()
	writer = tf.summary.FileWriter("./check/")
	for i in range(100):
		session.run(train_op, feed_dict)
		track_dict = session.run(fetch_dict, feed_dict)
		writer.add_summary(track_dict["summary_op"], i)
		saver.save(session, "./check/", i)
		print track_dict["loss"]

if __name__ == "__main__":
	train()
